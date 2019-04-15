#If_then statment in action 
echo "Enter source and target files names: "
read source target 
if mv $source $target
then
echo "Your file has been move successfully"
else
echo "The file could not be rename"
fi
