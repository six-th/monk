#!/bin/bash

#��������
set -x

#debug
CMAKE_BUILD_TYPE=Debug

source run_make.sh


#clean|all
case $1 in
	[Cc]lean)
		clean
		exit $?
		;;
	[Cc]lean[Aa]ll)
		cleanall
		exit $?
		;;
esac

#make
compile
exit $?

#�رջ���
set +x