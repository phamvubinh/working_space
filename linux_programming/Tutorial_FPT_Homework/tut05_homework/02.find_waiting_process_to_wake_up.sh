#!/bin/bash
# Find all running process
# Find process of program name
# Ignore the grep process
# Convert the result to an array of strings
RESULT=($(ps aux | grep ./02.wait_signal_program | grep -v "grep"))
# The number 2 string is PID process
PID=${RESULT[1]}
# Check if PID exist
if [[ $PID != "" ]]; then
	echo "Found PID of ./02.wait_signal_program " $PID 
	# Now we run the program to send signal to waiting signal program with found PID
	echo "Run ./02.send_wakeup_signal to wakeup it"
	./02.send_wakeup_signal $PID
	#Check PID again 
	RESULT=($(ps aux | grep ./02.wait_signal_program | grep -v "grep"))
	# The number 2 string is PID process
	NEWPID=${RESULT[1]}
	if [[ ($NEWPID != $PID ) || ($RESULT == "" ) ]]; then
		echo "Succesed waked up"
	fi
else
	echo "Not found running process"
fi
