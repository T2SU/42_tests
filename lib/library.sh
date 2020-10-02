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

# Check Norminette
check_norminette()
{
	echo "Norminette 검사..."
	NN=$(find . \( -name "*.h" -o -name "*.c" \) -print0 | xargs -0 $NORMINETTE)
	echo "$NN"
	echo $NN | grep -E "Error|Warning" >&0
	if [ ! $? -eq 1 ]
	then
		return 1
	fi
	return 0
}

reset_score()
{
	export SCORE=0
	export FAIL=0
	export TOTAL=0
}

add_score()
{
	if [[ $FAIL == 0 ]]
	then
		export SCORE=$(($SCORE+$1))
		echo "$1""점 획득. 현재 점수: $SCORE"
	fi
}

add_total()
{
	export TOTAL=$(($TOTAL+$1))
}

fail_score()
{
	export FAIL=1
}

print_score()
{
	echo "Score: $SCORE/$TOTAL"
}

if [ ! -f "$ROOT/norminette.conf" ]
then
	echo "norminette.conf 파일을 설정해주세요. norminette 검사시 실행할 norminette 클라이언트 프로그램 경로입니다. (norminette.conf.sample 참조)"
	exit 1
fi

_NORMINETTE=$(cat $ROOT/norminette.conf)
export NORMINETTE=$(eval echo $_NORMINETTE)
echo "Norminette path: $NORMINETTE"
