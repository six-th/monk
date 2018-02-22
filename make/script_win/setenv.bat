::@echo off

::������
@if "%1" == "64" goto 64
@if "%1" == "32" goto 32

:64
set CMAKE_BUILD_VERSION=x64
call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x64
goto env

:32
set CMAKE_BUILD_VERSION=i386
call "%VS140COMNTOOLS%..\..\VC\vcvarsall.bat" x86

:env
@echo on


::������Ŀ��Ŀ¼,ת����б��Ϊб��, E:\AA\BB\CC -->> E:/AA/BB/CC
cd ..\..\
set MONK_PATH=%cd:\=/%


::���û�������
set CMAKE_PLATFORM_NAME=win
set CMAKE_PLATFORM_VERSION=all

set MONK_PLATFORM=%CMAKE_PLATFORM_NAME%_%CMAKE_PLATFORM_VERSION%_%CMAKE_BUILD_VERSION%
set MONK_TARGET=%MONK_PATH%/%MONK_PLATFORM%/target
set MONK_BUILD=%MONK_PATH%/%MONK_PLATFORM%/build
set MONK_MAKE=%MONK_PATH%/make
set MONK_DEPS=%MONK_PATH%/deps
set MONK_SRC=%MONK_PATH%/src

@echo off
set PATH=%MONK_MAKE%/script_win;%PATH%
@echo on