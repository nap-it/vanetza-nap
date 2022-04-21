#!/bin/sh
if [ $START_EMBEDDED_MOSQUITTO = true ] ; then
    /usr/sbin/mosquitto -c /etc/mosquitto/mosquitto.conf &>/dev/null &
    sleep 2
fi
/root/go/src/dds-vanetza-service/main /vanetza/tools/socktap/config.ini /root/go/src/dds-vanetza-service/Vanetza_DDS_Spec.xml &>/dev/null &
sleep 1
/usr/local/bin/socktap -c tools/socktap/config.ini
