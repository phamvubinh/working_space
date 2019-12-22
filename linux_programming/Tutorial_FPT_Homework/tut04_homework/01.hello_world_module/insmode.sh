#!/bin/bash

if [ $1 -eq 1 ]; then
	echo "installing module"
	sudo insmod hello_world_module.ko
elif [ $1 -eq 0 ]; then
	echo "removing module"
	sudo rmmod hello_world_module
else 
	echo "./insmod 1 for install module"
	echo "./insmod 0 for remove module"
fi

echo "Checking result in dmesg"
dmesg | tail -10