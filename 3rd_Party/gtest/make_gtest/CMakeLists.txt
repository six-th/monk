PROJECT(googletest)

CMAKE_MINIMUM_REQUIRED(VERSION 3.18)
CMAKE_POLICY(VERSION 3.18)

INCLUDE($ENV{MK_PATH}/make/begin.cmake)

SET(TARGET_NAME gtest)
SET(TARGET_TYPE ARCHIVE)

#引用路径
INCLUDE_DIRECTORIES(../googletest/googletest/include;
                    ../googletest/googletest;)

#待编译文件(gtest-all.cc会include所有.cc源文件)
SET(INCLUDE_SOURCE_FILES    ../googletest/googletest/src/gtest-all.cc)

INCLUDE($ENV{MK_PATH}/make/end.cmake)

