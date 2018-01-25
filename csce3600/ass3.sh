#!/bin/bash
echo Please select one of the options:
printf "\n"
echo Option: 1, Option: 2, Option: 3
printf "\n"
printf ">"

read selection

case $selection in
	1)
		echo hey you picked option 1!
		;;
	2)
		echo here is option 2!
		;;
	3)
		echo this is option 3..
		;;
	*)
		echo Sorry, thats not an option!
		;;
esac
