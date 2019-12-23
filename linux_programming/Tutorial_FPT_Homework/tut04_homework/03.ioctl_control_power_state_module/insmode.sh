#!/bin/bash
if [ $1 -eq 1 ]; then
	echo "----- Installing module ------"
	sudo insmod $2
	echo "----- Checking result in dmesg -----"
	dmesg | tail -5
	echo "----- Checking result by lsmod -----"
	lsmod
elif [ $1 -eq 0 ]; then
	echo "----- Removing module -----"
	sudo rmmod $2
	echo "----- Checking result in dmesg -----"
	dmesg | tail -5
	echo "----- Delete device file under /dev -----"
	sudo rm -rf /dev/power_state
elif [ $1 -eq 2 ]; then
	echo "----- Making device file -----"
	# Get the MAJOR number from /proc/devices of skeleton_module_2
	MAJOR=$(cat /proc/devices | grep "power_state" | sed 's/ .*//') 
	echo $MAJOR
	# Create a device file under /dev/ 
	sudo mknod /dev/power_state c $MAJOR 0
	# Change mode to read write module  
	sudo chmod 777 /dev/power_state
	echo "----- Reading device file -----"
	cat /dev/power_state
	echo "----- Writing device file -----"
	echo 1 > /dev/power_state
	echo "----- Checking result in dmesg -----"
	dmesg | tail -5
else 
	echo "./insmod 1 <module.ko> for install module"
	echo "./insmod 0 <module> for remove module"
	echo "./insmod 2 for making device file"
fi
