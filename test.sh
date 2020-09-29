#!/bin/sh

# 42 과제 테스트 메인 셸 스크립트
#
#   Created by : smun (smun@student.42seoul.kr)
#
#   First Date : 2020-09-28 16:22
#

export MODE="$1"
export ROOT=$(pwd)

# config.conf 파일을 읽어 TARGET 변수에 저장. 읽어올 수 없는 경우라면 실패.
get_directory()
{
	# 매개변수로 전달받은 모드가 없을 경우
	#  = 메인 셸 스크립트에 매개변수를 전달하지 않았을 경우.
	if [ -z $1 ]
	then
		echo "Require a mode name"
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
		echo "Unknown target path. (mode: $MODE)"
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

# 라이브러리 셸 스크립트 로드
. ./library.sh

# 디렉토리 얻기 함수 호출 후 검증 함수 호출
get_directory $MODE
validate_directory $MODE

# 디렉토리 이동
cd $TARGET

echo "Welcome to 42 test scripts."


if [[ $MODE == "libft" ]]
then
	disclaimer
	echo "Libft directory: $TARGET";
	$ROOT/libft/libft.sh $ROOT
fi
