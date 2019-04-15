echo "Enter a name between 50 and 100:"
read num
if [ $num -le 100 -a $num -ge 50 ]  #-a -s and
then 
	echo "You are within limits."
else 
	echo "You are out of limits."
fi

