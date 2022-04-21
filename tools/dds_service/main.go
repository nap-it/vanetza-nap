package main

import (
	"fmt"
	"log"
	"net"
	"os"
	"strings"
	"sync"

	xml "github.com/antchfx/xmlquery"
	rti "github.com/rticommunity/rticonnextdds-connector-go"
	ini "gopkg.in/ini.v1"
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

func vanetza_to_dds(wg *sync.WaitGroup) {
	defer wg.Done()

	for {
		// read data
		data := make([]byte, 9999)
		_, _, err := server_socket.ReadFromUDP(data)
		if err != nil {
			fmt.Println("read data failed!", err)
			continue
		}
		fmt.Printf("%s\n\n", data)
		str_data := string(data)
		index := strings.Index(str_data, ";")
		topic := str_data[:index]
		message := str_data[index+1:]
		outputs[topic].Instance.SetString("message", message)
		outputs[topic].Write()
	}
}

func dds_to_vanetza(wg *sync.WaitGroup) {
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
						senddata := []byte(tuple.topic + ";" + message)
						_, err = client_socket.Write(senddata)
						if err != nil {
							fmt.Println("send data failed!", err)
							return
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
	server_port, _ := cfg.Section("general").Key("to_dds_port").Int()
	client_port, _ := cfg.Section("general").Key("from_dds_port").Int()

	server_socket, _ = net.ListenUDP("udp4", &net.UDPAddr{
		IP:   net.IPv4(127, 0, 0, 1),
		Port: server_port,
	})
	defer server_socket.Close()

	client_socket, _ = net.DialUDP("udp4", nil, &net.UDPAddr{
		IP:   net.IPv4(127, 0, 0, 1),
		Port: client_port,
	})
	defer client_socket.Close()

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

	go dds_to_vanetza(&wg)
	go vanetza_to_dds(&wg)

	wg.Wait()

}
