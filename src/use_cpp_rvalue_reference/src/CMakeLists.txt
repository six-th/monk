PROJECT(use_cpp_rvalue_reference)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
CMAKE_POLICY(VERSION 2.8)

INCLUDE($ENV{MK_PATH}/make/begin.cmake)

SET(TARGET_TYPE RUNTIME)
SET(TARGET_NAME use_cpp_rvalue_reference)
SET(AUTO_RUN OFF)

#������
SET(NEED_GTEST TRUE)
SET(NEED_BENCHMARK TRUE)
SET(NEED_BOOST_FULL TRUE)
SET(NEED_MARKCORE TRUE)

# ����Ŀ¼
ADD_SOURCE_DIRS(./usage;)

IF(WIN32)
ELSE()
    #���÷���ֵ�Ż�RVO
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors -Wno-unused-variable")
ENDIF()

#���� main.cpp
set(INCLUDE_SOURCE_FILES ${INCLUDE_SOURCE_FILES} ${MK_PATH}/markcore/ut/main.cpp)

INCLUDE($ENV{MK_PATH}/make/end.cmake)



