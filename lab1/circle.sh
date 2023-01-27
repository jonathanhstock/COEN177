# Name: Jonathan Stock
# Date: Wednesday
# Title: Lab1 - task
# Description: This program computes the area of the circle given the radius from the user's input after checking who the logged in user is

#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "jonathanstock" ]
then
	echo "Now you can proceed!"
else
	echo "Check who logged in!"
	exit 1
fi

response="Yes"
while [ $response != "No" ]
do
	echo "Enter radius of circle: "
	read radius
	area=`echo "$radius * $radius * 3.14" | bc`
	echo "The area of the circle is $area"

	echo "Would you like to repeat for another circle [Yes/No]?"
	read response
done
