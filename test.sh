#!/bin/sh

# 42 과제 테스트 메인 셸 스크립트
#
#   Created by : smun (smun@student.42seoul.kr)
#
#   First Date : 2020-09-28 16:22
#

export ROOT=$(pwd)
export SKIP_NORMINETTE=0

# 라이브러리 셸 스크립트 로드
. $ROOT/lib/library.sh
echo

# 옵션 파싱
for i in "$@"
do
case $i in
    -sn|--skip-norminette)
		export SKIP_NORMINETTE=1
		shift
    ;;
    --help)
		echo "usage: test.sh [-sn|--skip-norminette] [modes] (options)"
		echo "display all available modes: test.sh --display-modes"
		echo "* options: depends on running mode."
		echo "  - libft: functions what you want test. (ft_strlen, ft_memset, ...)"
		exit
    ;;
    --display-modes)
		print_available_modes
		exit
    ;;
    *)
    	break
    ;;
esac
done

export MODE="$1"
shift

# config.conf 파일을 읽어 TARGET 변수에 저장. 읽어올 수 없는 경우라면 실패.
get_directory()
{
	# 매개변수로 전달받은 모드가 없을 경우
	#  = 메인 셸 스크립트에 매개변수를 전달하지 않았을 경우.
	if [ -z $1 ]
	then
		echo "Require a mode name. (usage: ./test.sh {MODE_NAME})"
		print_available_modes
		exit 1
	fi

	# config.conf 파일이 없을 경우
	if [ ! -f "config.conf" ]
	then
		echo "Please set a config file. (config.conf)"
		exit 1
	fi

	# config.conf 파일을 읽은 후 매개변수로 전달된 모드를 검색하여 경로 추출.
	# 그런 다음 TARGET 매개변수에 정의.
	export TARGET=$(cat config.conf | grep -oE "$1\=.*" | sed "s/$1=//g")
}

# 읽어온 TARGET 변수의 디렉토리가 올바른 디렉토리 및 존재하는 디렉토리인지 확인.
validate_directory()
{
	# 대상 디렉토리를 읽어오지 못했을 경우. (config.conf에 없을 경우?)
	if [ -z $TARGET ]
	then
		echo "Unknown mode's target path. (mode: $MODE)"
		print_available_modes
		exit 1
	fi

	local _TARGET=$(eval echo $TARGET)
	# 대상 디렉토리가 존재하지 않는 디렉토리 일 경우.
	if [ ! -d $_TARGET ]
	then
		echo "Invalid target directory: '$TARGET'. (mode: $MODE)"
		exit 1
	fi
	export TARGET=$_TARGET
}

# 시스템 정보 출력
echo ":: HostName"
hostname
echo

echo ":: System Information"
uname -a
echo

if [[ $(uname -s) == "Darwin" ]]
then
echo ":: Apple Clang Information"
	clang --version
else
echo ":: GCC Information"
	gcc --version
fi
echo

# norminette 실행 가능한지 검사
if [ $SKIP_NORMINETTE -eq 0 ]
then
	N=$($NORMINETTE -v)
	if [[ ! $N == *"Norminette version:"* ]]
	then
		echo "Norminette 를 실행할 수 없습니다. Norminette가 올바르게 설치되어 있는지 확인해주세요. 또는, --skip-norminette 옵션을 사용해 Norminette 검사를 생략하는 것을 고려해보세요."
		exit 1
	fi
	echo ":: Norminette Information"
	echo $N
	echo
fi

# tmp 폴더 생성
mkdir -p tmp

# 디렉토리 얻기 함수 호출 후 검증 함수 호출
get_directory $MODE
validate_directory $MODE

# 디렉토리 이동
cd $TARGET

echo "Welcome to 42 test scripts."


if [[ $MODE == "libft" ]]
then
	# disclaimer
	echo "Libft directory: $TARGET";
	$ROOT/libft/libft.sh "$ROOT" $SKIP_NORMINETTE "$@"
fi

