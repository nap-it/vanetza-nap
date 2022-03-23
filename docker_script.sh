
#!/bin/sh
#/usr/sbin/mosquitto >/dev/null &
/usr/local/bin/socktap -l ethernet -i eth0 -a ca --security=none --non-strict --gn-version 1
