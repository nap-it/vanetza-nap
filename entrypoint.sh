#!/bin/sh
if [ $START_EMBEDDED_MOSQUITTO = true ] ; then
    /usr/sbin/mosquitto -c /etc/mosquitto/mosquitto.conf &>/dev/null &
fi
/usr/local/bin/socktap -c tools/socktap/config.ini
