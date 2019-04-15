echo "Enter a character:"
read var
if [ `echo $var | wc -c` -eq 2 ]
then 
	echo "You enter a character."
else 
	echo "Invalid input."
fi
