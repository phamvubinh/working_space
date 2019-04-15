echo "Enter a name: "
read fname
if [ -f $fname ]
then 
	echo "You indeed entered a file name."
else
	echo "Don't provide me a fake file name."
fi
