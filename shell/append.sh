echo "Enter file name:"
read fname
if [ -f $fname ]
then 
	if [ -w $fname ]
	then
		echo "Type matter to append. To quit press ctrl+d."
		cat >> $fname
	else 
		echo "You do not permission to write."
	fi
fi 
