echo "Enter a character:"
read var
case $var in 
[a-z])
	echo "You enter a lowercase alphabet."
	;;
[A-Z]) 
	echo "You enter a upercase alphabet."
	;;
[0-9])
	echo "You enter a digit."
	;;
?)
	echo "You enter a special symbol."
	;;
*) 
	echo "You enter more than one character."
	;;
esac
