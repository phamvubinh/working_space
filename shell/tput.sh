#tput in action 
tput clear
echo " total number of rows on screen=\c "
tput lines 
echo " total number of colums on screen=\c "
tput cols
tput cup 15 20
tput bold
echo " this should be in bold "
echo "\033[0mbye bye\033[0m"

