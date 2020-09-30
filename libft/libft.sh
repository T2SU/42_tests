#!/bin/sh

# 42 libft 테스트 셸 스크립트
#
#   Created by : smun (smun@student.42seoul.kr)
#
#   First Date : 2020-09-28 16:40
#

export ROOT="$1"

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

echo "1. <norminette> 검사 수행"
check_norminette
if [ ! $? -eq 0 ]
then
	echo "[실패] Norminette 위반!"
	exit 1
fi
echo "통과! :D"
echo

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

# 점수 리셋
reset_score


# 테스트 수행 함수
do_test()
{
	echo "테스트:: $1"
	gcc -Wall -Werror -Wextra -I includes/ -L . -l ft $ROOT/libft/$1.c -o $ROOT/tmp/$1.t
	if [ ! $? -eq 0 ]
	then
		echo "[실패] $1 테스트 코드가 컴파일 되지 않았습니다."
		exit 1
	fi

	# 테스트 수행
	$ROOT/tmp/$1.t
	if [ $? -eq 0 ]
	then
		echo "$1 테스트 통과! :D"
		add_score $2
	else
		echo "$1 테스트 실패.. :( [결과 코드:$?]"
		fail_score
	fi
}

# 실제 테스트 수행
do_test "ft_memset" 5
do_test "ft_bzero" 5
do_test "ft_memcpy" 5
do_test "ft_memccpy" 5
do_test "ft_memmove" 5
do_test "ft_memchr" 5
do_test "ft_memcmp" 5
do_test "ft_strlen" 5
do_test "ft_strlcpy" 5
do_test "ft_strlcat" 5


# 결과
echo
echo "테스트 완료! :D"
print_score
