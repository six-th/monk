PROJECT(use_brpc_client)

#version
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
CMAKE_POLICY(VERSION 3.17)

#begin
INCLUDE($ENV{MK_PATH}/make/begin.cmake)

#Ŀ������
SET(TARGET_NAME use_brpc_client)
SET(TARGET_TYPE RUNTIME)
SET(AUTO_RUN OFF)

#������
SET(NEED_GTEST TRUE)
SET(NEED_GFLAGS TRUE)
SET(NEED_PROTOBUF TRUE)
SET(NEED_BRPC TRUE)
SET(NEED_MARKCORE TRUE)

ADD_DEFINITIONS(-DGFLAGS_NS=google)

include_directories(../proto)
SET(INCLUDE_SOURCE_FILES    ../proto/use_brpc.pb.cc)

#todo
#include(${MK_PATH}/3rd_Party/protobuf/protoc-compile.cmake)
#ADD_BUILD_PROTO_FILES( ../  xxx.proto)

#end
INCLUDE($ENV{MK_PATH}/make/end.cmake)
