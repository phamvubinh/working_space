#!/bin/bash
# Find all running process
# Find process of program name
# Ignore the grep process
# Convert the result to an array of strings
RESULT=($(ps aux | grep ./server_share_memory | grep -v "grep"))
# The number 2 string is PID process
PID=${RESULT[1]}
# Check if PID exist
if [[ $PID != "" ]]; then
	echo "Found PID of ./server_share_memory " $PID 
	# Now we run the program to send signal to waiting signal program with found PID
	echo "Run ./client_share_memory to wakeup it"
	./client_share_memory $PID
else
	echo "Not found running process"
fi
