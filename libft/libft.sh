#!/bin/sh

# 42 libft 테스트 셸 스크립트
#
#   Created by : smun (smun@student.42seoul.kr)
#
#   First Date : 2020-09-28 16:40
#

export ROOT=$1

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
. $ROOT/library.sh

echo "1. <make fclean> 실행"
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

echo "2. <make all> 실행"
make all

COUNT=$(find . -name "libft.a" | wc -l)
if [[ $COUNT == 0 ]]
then
	echo "[실패] <make all> 실행 후 libft.a 파일이 발견되지 않았습니다."
	exit 1
fi
echo "통과! :D"
echo

reset_score

echo "테스트 성공! :D"
print_score
