#!/bin/sh

# Disclaimer
disclaimer()
{
	echo
	echo "       <<< Disclaimer >>>"
	echo
	echo " * Your use of this script and your reliance on"
	echo "   any result is solely at your own risk. "
	echo "   Before run the script, please confirm "
	echo "   carefully the its sources."
	echo
    read -p "continue? (y/n): " ANSWER
    case $ANSWER in
        [Yy]* ) break;;
        * ) exit;;
    esac
}

reset_score()
{
	export SCORE=0
}

add_score()
{
	export SCORE=$(($SCORE+$1))
}

print_score()
{
	echo "Score: $SCORE/100"
}
