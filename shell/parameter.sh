#This program change a file name
mv $1 $2
echo "Moved $1 to $2"
echo "Enter the new file name"
read new_name
mv $2 $new_name
echo "Moved $2 to $new_name"
echo "Change permission of a file"
read chmod_file
chmod 777 $chmod_file

