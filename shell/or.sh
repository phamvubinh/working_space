echo "Enter a lowercase character:"
read var
if [ `echo $var | wc -c` -eq 2 ]
then 
	if [ $var = a -o $var = e -o $var = i -o $var = o -o $var = u  ]
	then 
		echo "You enter a vowvel"
	else 
		echo "You didn't enter a vowvel"
	fi	
else 
	echo "Invalid input."
fi
