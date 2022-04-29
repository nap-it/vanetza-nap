package main

import (
	"fmt"
	"log"
	"net"
	"os"
	"strings"
	"sync"

	"github.com/Shopify/sysv_mq"
	xml "github.com/antchfx/xmlquery"
	rti "github.com/rticommunity/rticonnextdds-connector-go"
	"gopkg.in/ini.v1"
)

type tuple struct {
	input *rti.Input
	topic string
}

var outputs = map[string]*rti.Output{}
var connector *rti.Connector
var inputs []tuple
var server_socket *net.UDPConn
var client_socket *net.UDPConn

func vanetza_to_dds(wg *sync.WaitGroup, mq *sysv_mq.MessageQueue) {
	defer wg.Done()

	for {
		str_data, _, err := mq.ReceiveString(0, 0)
		if err != nil {
			fmt.Println(err)
		}
		index := strings.Index(str_data, ";")
		if index == -1 {
			fmt.Printf("Error: vanetza_to_dds missing ';', message: %s\n", str_data)
			continue
		}
		topic := str_data[:index]
		message := str_data[index+1:]
		outputs[topic].Instance.SetString("message", message)
		outputs[topic].Write()
	}
}

func dds_to_vanetza(wg *sync.WaitGroup, mq *sysv_mq.MessageQueue) {
	defer wg.Done()

	for {
		connector.Wait(-1)
		for _, tuple := range inputs {
			tuple.input.Take()
			numOfSamples, _ := tuple.input.Samples.GetLength()
			for j := 0; j < numOfSamples; j++ {
				valid, _ := tuple.input.Infos.IsValid(j)
				if valid {
					message, err := tuple.input.Samples.GetString(j, "message")
					if err != nil {
						log.Println(err)
					} else {
						err = mq.SendString(tuple.topic+";"+message, 1, 0)
						if err != nil {
							fmt.Println(err)
						}
					}
				}
			}
		}
	}
}

func main() {
	cfg, err := ini.Load(os.Args[1])
	if err != nil {
		fmt.Println("Config file read error", err)
		os.Exit(1)
	}
	to_dds_key, _ := cfg.Section("general").Key("to_dds_key").Int()
	from_dds_key, _ := cfg.Section("general").Key("from_dds_key").Int()

	to_dds_mq, err := sysv_mq.NewMessageQueue(&sysv_mq.QueueConfig{
		Key:     to_dds_key,               // SysV IPC key
		MaxSize: 15008,                    // Max size of a message
		Mode:    sysv_mq.IPC_CREAT | 0600, // Creates if it doesn't exist, 0600 permissions
	})

	from_dds_mq, err := sysv_mq.NewMessageQueue(&sysv_mq.QueueConfig{
		Key:     from_dds_key,             // SysV IPC key
		MaxSize: 15008,                    // Max size of a message
		Mode:    sysv_mq.IPC_CREAT | 0600, // Creates if it doesn't exist, 0600 permissions
	})

	connector, _ = rti.NewConnector("participant_library::vanetza", os.Args[2])
	defer connector.Delete()

	f, err := os.Open(os.Args[2])
	doc, err := xml.Parse(f)
	if err != nil {
		panic(err)
	}
	for _, n := range xml.Find(doc, "//subscriber[@name='vanetza_subscriber']/*") {
		topic := n.SelectAttr("name")
		input, err := connector.GetInput("vanetza_subscriber::" + topic)
		inputs = append(inputs, tuple{input, topic})
		if err != nil {
			log.Panic(err)
		}
		fmt.Println("Subscribed to DDS topic " + n.SelectAttr("topic_ref"))
	}
	for _, n := range xml.Find(doc, "//publisher[@name='vanetza_publisher']/*") {
		topic := n.SelectAttr("name")
		output, err := connector.GetOutput("vanetza_publisher::" + topic)
		if err != nil {
			log.Panic(err)
		}
		outputs[topic] = output
	}

	var wg sync.WaitGroup
	wg.Add(2)
	fmt.Println("Starting")

	go dds_to_vanetza(&wg, from_dds_mq)
	go vanetza_to_dds(&wg, to_dds_mq)

	wg.Wait()

}
