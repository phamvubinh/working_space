#!/bin/sh
NUMBER=`ls -l|grep 'test'|wc -l`
echo $NUMBER
touch log

while [ $NUMBER -gt 0 ]; do
	echo $NUMBER
	/bin/cat test$NUMBER >> log
	let NUMBER=NUMBER-1
done

/bin/cat log
	
