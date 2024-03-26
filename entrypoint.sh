#!/bin/sh

update_config_field() {
    if grep -qE "^\[$2\]" "$1" && grep -qE "^$3\s*=" "$1"; then
        val=$(grep -E "^\[$2\]" -A 1000 "$1" | grep -m 1 -E "^$3\s*=" | sed -E 's/^[^=]*=\s*//')
        sed "/^\[$5]/,/^\[/{s/^$6[[:space:]]*=.*/$6 = $val/}" "$4" > "$4.tmp" && cp "$4.tmp" "$4" && rm "$4.tmp";
    else
        echo "Field '$3' in section '$2' not found in '$1'. Skipping update."
    fi
}

if [ -e "/info.ini" ]; then
    update_config_field "/info.ini" "general" "id" "/config.ini" "station" "id"
    update_config_field "/info.ini" "mobility" "stationType" "/config.ini" "station" "type"
    update_config_field "/info.ini" "mobility" "latitude" "/config.ini" "station" "latitude"
    update_config_field "/info.ini" "mobility" "longitude" "/config.ini" "station" "longitude"
    update_config_field "/info.ini" "mobility" "macAddr" "/config.ini" "station" "mac_address"
    update_config_field "/info.ini" "mobility" "interface" "/config.ini" "general" "interface"
    update_config_field "/info.ini" "general" "id" "/config.ini" "general" "dds_domain_id"
    echo "Config update process complete"
else
    echo "No global board config file found. Skipping config update process"
fi

IP_ADDR=$(ip -f inet addr show eth0 | awk '/inet / {print $2}')
GW_ADDR=$(ip r | awk '/default / {print $3}')
BR_ID=br0

if [ -n "$SUPPORT_MAC_BLOCKING" ] && [ $SUPPORT_MAC_BLOCKING = true ] ; then
    brctl addbr $BR_ID
    ip a a $IP_ADDR dev $BR_ID
    ip a d  $IP_ADDR dev eth0
    brctl addif $BR_ID eth0
    ip link set $BR_ID up
    ip r a default via $GW_ADDR
fi

printf '#!/bin/sh\nebtables -A INPUT -s $1 -j DROP;' > /bin/block
printf '#!/bin/sh\nebtables -D INPUT -s $1 -j DROP;' > /bin/unblock
chmod +x /bin/block
chmod +x /bin/unblock

if [ -n "$START_EMBEDDED_MOSQUITTO" ] && [ $START_EMBEDDED_MOSQUITTO = true ] ; then
    printf "\nlistener ${EMBEDDED_MOSQUITTO_PORT} 0.0.0.0\nallow_anonymous true\n\n" > mosquitto.conf
    /usr/sbin/mosquitto -c mosquitto.conf &>/dev/null &
    sleep 2
fi

/usr/local/bin/socktap -c /config.ini
