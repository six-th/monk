@echo off

set CUR_CMAKELISTS_PATH=%cd%
set BUILD_RELATIVE_PATH=
echo ** ---make init---

::获取当前目录的目录名称
:getcurrentname
set PNAME=
for %%i in ("%cd%") do ( set PNAME=%%~nxi)

:: %cd% == C:\的时候,PNAME为空
if "%PNAME%" == "" goto endgetname

::第一次循环时不用拼接,否则结尾会多一个反斜杠
if "%BUILD_RELATIVE_PATH%" == "" goto first_getname

::第二次及之后循环时,拼接 BUILD_RELATIVE_PATH
set BUILD_RELATIVE_PATH=%PNAME%\%BUILD_RELATIVE_PATH%
goto filter_PNAME

:first_getname
set BUILD_RELATIVE_PATH=%PNAME%
goto filter_PNAME

:filter_PNAME
if "%PNAME%" == "mark" goto endgetname
cd ..
goto getcurrentname

:: 结束循环
:endgetname
echo [BUILD_RELATIVE_PATH]= %BUILD_RELATIVE_PATH%

:: 进入build目录
set BUILD_ABSOLUTE_PATH=%MK_PACKAGE:/=\%\build
set BUILD_ABSOLUTE_PATH=%BUILD_ABSOLUTE_PATH%\%CMAKE_BUILD_TYPE%\%BUILD_RELATIVE_PATH%
echo [cd]= %BUILD_ABSOLUTE_PATH%


echo ** ---make run------

::maked clean
if %MAKE_CMD% == "" (
    goto make
)

::maked clean
if %MAKE_CMD% == "clean" (
    goto make_clean
)

::maked cleanall
if %MAKE_CMD% == "cleanall" (
    set CLEAN_ALL="1"
    goto make_clean
)

:make
if not exist %BUILD_ABSOLUTE_PATH% (
    md %BUILD_ABSOLUTE_PATH%
)
cd %BUILD_ABSOLUTE_PATH%

if not exist ALL_BUILD.vcxproj (
    cmake -G%CMAKE_GENERATOR% -DCMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE% -DAUTO_RUN=0 %* %CUR_CMAKELISTS_PATH%
)
:: 执行编译
msbuild ALL_BUILD.vcxproj /nologo /p:Configuration=%CMAKE_BUILD_TYPE% /p:Platform=%MK_SYSTEM_TYPE% /m:4  /verbosity:minimal
goto make_end


:make_clean
if exist %BUILD_ABSOLUTE_PATH% (
    cd %BUILD_ABSOLUTE_PATH%
    if exist ALL_BUILD.vcxproj (
        msbuild ALL_BUILD.vcxproj /nologo /p:Configuration=%CMAKE_BUILD_TYPE%  /p:Platform=%MK_SYSTEM_TYPE% /verbosity:minimal /t:Clean
    )
)
goto make_clean_all


:make_clean_all
if exist %BUILD_ABSOLUTE_PATH% (
	:: 删除makefile目录
    if %CLEAN_ALL% == "1" (
        echo [rd BUILD_ABSOLUTE_PATH]= %BUILD_ABSOLUTE_PATH%"
        cd ..
        rd /s /q %BUILD_ABSOLUTE_PATH%
    )
)


:make_end
echo ** ---make end------
@echo on
cd %CUR_CMAKELISTS_PATH%

