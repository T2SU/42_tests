#!/bin/sh

print_available_modes()
{
	echo ":: Available Testing Modes ::"
	cat config.conf | grep -oE ".*\=" | sed 's/=//g;' | tr '\n' ',' | sed '$s/ $/\n/;s/,/, /g;$s/, $//'
}

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
	export FAIL=0
}

add_score()
{
	if [[ $FAIL == 0 ]]
	then
		export SCORE=$(($SCORE+$1))
		echo "$1""점 획득. 현재 점수: $SCORE"
	fi
}

fail_score()
{
	export FAIL=1
}

print_score()
{
	echo "Score: $SCORE/100"
}
