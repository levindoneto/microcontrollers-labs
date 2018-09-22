#!/bin/bash
while true ; do
	echo -n "0" > /sys/class/gpio/gpio7/value
	sleep 1
	echo -n "1" > /sys/class/gpio/gpio7/value
	sleep 1
done
