#!/bin/sh

# 42 libft 테스트 셸 스크립트
#
#   Created by : smun (smun@student.42seoul.kr)
#
#   First Date : 2020-09-28 16:40
#

export ROOT="$1"
shift
export SKIP_NORMINETTE="$1"
shift
export OPTIONS=$(echo "$@" | tr ' ' '\n')
export OPTIONS_NUM="$#"
shift $#

echo "                                               "
echo "  ___       ___  ________  ________ _________   "
echo " |\  \     |\  \|\   __  \|\  _____\\___   ___\ "
echo " \ \  \    \ \  \ \  \|\ /\ \  \__/\|___ \  \_| "
echo "  \ \  \    \ \  \ \   __  \ \   __\    \ \  \  "
echo "   \ \  \____\ \  \ \  \|\  \ \  \_|     \ \  \ "
echo "    \ \_______\ \__\ \_______\ \__\       \ \__\\"
echo "     \|_______|\|__|\|_______|\|__|        \|__|"
echo "                                               "
echo "                                               "
echo "  42 libft self test script"
echo
echo "       created by smun <smun@student.42seoul.kr>"
echo
echo

# 라이브러리 셸 스크립트 로드
. $ROOT/lib/library.sh

if [ $SKIP_NORMINETTE -eq 0 ]
then
	echo "1. <norminette> 검사 수행"
	check_norminette
	if [ ! $? -eq 0 ]
	then
		echo "[실패] Norminette 위반!"
		exit 1
	fi
	echo "통과! :D"
	echo
else
	echo "1. <norminette> 검사 통과!"
fi

echo "2. <make fclean> 실행"
make fclean

COUNT=$(find . -name "*.o" -o -name "libft.a" | wc -l)
if [[ $COUNT > 0 ]]
then
	echo "[실패] <make fclean> 실행 후 아래 파일이 발견되었습니다."
	find . -name "*.o" -o -name "libft.a"
	exit 1
fi
echo "통과! :D"
echo

echo "3. <make all> 실행"
make all

if [ ! $? -eq 0 ]
then
	echo "[실패] <make all> 에서 컴파일에 실패했습니다."
	exit 1
fi
if [ ! -f "libft.a" ]
then
	echo "[실패] <make all> 실행 후 libft.a 파일이 발견되지 않았습니다."
	exit 1
fi
echo "통과! :D"
echo

contains_test()
{
	for x in $OPTIONS
	do
		if [[ $x == $1 ]]
		then
			return 1
		fi
	done
	return 0
}

# 테스트 수행 함수
do_test()
{
	contains_test "$1";
	R=$?
	if [ ${OPTIONS_NUM} -eq 0 ] || [ $R -ne 0 ]
	then
		echo "테스트:: $1"
		gcc -Wall -Werror -Wextra -I includes/ -L . -l ft $ROOT/libft/$1.c -o $ROOT/tmp/$1.t
		if [ ! $? -eq 0 ]
		then
			echo "[실패] $1 테스트 코드가 컴파일 되지 않았습니다."
			exit 1
		fi

		# 테스트 수행
		$ROOT/tmp/$1.t "${ROOT}/tmp"
		EXECUTABLE_STATUS_CODE=$?
		if [ $EXECUTABLE_STATUS_CODE -eq 0 ]
		then
			echo "$1 테스트 통과! :D"
			add_score 1
		elif [ $EXECUTABLE_STATUS_CODE -eq 134 ]
		then
			echo "$1 테스트 실패.. :( [Abort]"
			fail_score
		elif [ $EXECUTABLE_STATUS_CODE -eq 138 ]
		then
			echo "$1 테스트 실패.. :( [Bus Error]"
			fail_score
		elif [ $EXECUTABLE_STATUS_CODE -eq 139 ]
		then
			echo "$1 테스트 실패.. :( [Segmentation Fault]"
			fail_score
		else
			echo "$1 테스트 실패.. :( [결과 코드:$EXECUTABLE_STATUS_CODE]"
			fail_score
		fi
		add_total 1
	fi
}

# 실제 테스트 수행

echo
echo "-------------------------------"
echo
## Part. 1
echo ":: Part .1 functions"
echo
reset_score
do_test "ft_memset"
do_test "ft_bzero"
do_test "ft_memcpy"
do_test "ft_memccpy"
do_test "ft_memmove"
do_test "ft_memchr"
do_test "ft_memcmp"
do_test "ft_strlen"
do_test "ft_strlcpy"
do_test "ft_strlcat"
do_test "ft_strchr"
do_test "ft_strrchr"
do_test "ft_strnstr"
do_test "ft_strncmp"
do_test "ft_atoi"
do_test "ft_isalpha"
do_test "ft_isdigit"
do_test "ft_isalnum"
do_test "ft_isascii"
do_test "ft_isprint"
do_test "ft_toupper"
do_test "ft_tolower"
do_test "ft_calloc"
do_test "ft_strdup"
echo
print_score
echo
echo "-------------------------------"
echo

## Part. 2
echo ":: Part .2 functions"
echo
reset_score
do_test "ft_substr"
do_test "ft_strjoin"
do_test "ft_strtrim"
do_test "ft_split"
do_test "ft_itoa"
do_test "ft_strmapi"
do_test "ft_putchar_fd"
do_test "ft_putstr_fd"
do_test "ft_putendl_fd"
do_test "ft_putnbr_fd"
echo
print_score
echo
echo "-------------------------------"
echo

## Bonus Part.
echo ":: Part .Bonus functions"
echo
reset_score
# do_test "ft_lstnew"
# do_test "ft_lstadd_front"
# do_test "ft_lstsize"
# do_test "ft_lstlast"
echo
print_score
echo
echo "-------------------------------"
echo

# 결과
echo
echo "테스트 완료! :D"
