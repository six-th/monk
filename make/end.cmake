MESSAGE(STATUS "\n\n**include:end.cmake\n")

####################################################################################################
MESSAGE(STATUS "\n**deps-----------------------------------------------------------------------------")


#Ĭ�ϰ�������Ŀ¼
INCLUDE_DIRECTORIES(${MK_SRC}/markcore/include;)

# ���� boost �������
IF(${NEED_BOOST_BCP})
	INCLUDE_DIRECTORIES(${MK_PATH}/3rd_Party/boost/boost_bcp_1_75_0)
	ADD_DEFINITIONS(-DBOOST_ALL_NO_LIB -DBOOST_ALL_DYN_LINK -DBOOST_LIB_DIAGNOSTIC)
    SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} boost_bcp)
    IF(UNIX)
        LINK_DIRECTORIES(/usr/lib64/openmpi/lib)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmpi -lbz2")
        #-lbz2 -lm
    ELSE()
    ENDIF()
ENDIF()
IF(${NEED_BOOST_FULL})
	INCLUDE_DIRECTORIES(${MK_PATH}/3rd_Party/boost/boost_full_1_75_0/boost_1_75_0)
	ADD_DEFINITIONS(-DBOOST_ALL_NO_LIB -DBOOST_ALL_DYN_LINK -DBOOST_LIB_DIAGNOSTIC)
    SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} boost_full)
    IF(UNIX)
        LINK_DIRECTORIES(/usr/lib64/openmpi/lib)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmpi -lbz2")
    ELSE()
    ENDIF()
ENDIF()

# ���� googletest �������
IF(${NEED_GTEST})
	#gtest
	ADD_DEFINITIONS(-D__USING_GTEST__)
	INCLUDE_DIRECTORIES(${MK_PATH}/3rd_Party/gtest/googletest/googletest/include)
    SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} gtest)
    
	# gmock
	ADD_DEFINITIONS(-D__USING_GMOCK__)
	INCLUDE_DIRECTORIES(${MK_PATH}/3rd_Party/gtest/googletest/googlemock/include)
    SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} gmock)
	IF("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
		LINK_LIBRARIES(pthread)
	ENDIF()
ENDIF()

# ���� gflags
IF(${NEED_GFLAGS})
    include_directories(${MK_DEPS_PKGS}/gflags/include)
    seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/gflags/lib gflags)
    SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} gflags)
ENDIF()

# ���� leveldb
IF(${NEED_LEVELDB})
    IF(WIN32)
        include_directories(${MK_PATH}/3rd_Party/leveldb/leveldb/include)
        seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/__build/leveldb/${CMAKE_BUILD_TYPE} leveldb)
    ELSE()
        include_directories(${MK_DEPS_PKGS}/leveldb/include)
        seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/leveldb/lib64 leveldb)
    ENDIF()
    SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} leveldb)
ENDIF()

# ���� protobuf
IF(${NEED_PROTOBUF})
    IF(WIN32)
        #todo:
        #include_directories(${MK_PATH}/protobuf/include)
        seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/__build/protobuf/${CMAKE_BUILD_TYPE} protobufd)
        SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} protobufd)
    ELSE()
        include_directories(${MK_DEPS_PKGS}/protobuf/include)
        seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/protobuf/lib64 protobuf)
        SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} protobuf)
    ENDIF()
ENDIF()

# ���� brpc
IF(${NEED_BRPC})
    include_directories(${MK_DEPS_PKGS}/brpc/include)
    seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/gflags/lib gflags)
    seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/leveldb/lib64 leveldb)
    seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/protobuf/lib64 protobuf)
    seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/brpc/lib64 brpc)
    SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} brpc)
ENDIF()

# ���� makecore
IF(${NEED_MARKCORE})
	ADD_DEFINITIONS(-D__USING_MAKECORE__)
	INCLUDE_DIRECTORIES(${MK_SRC}/markcore/include;
						${MK_SRC}/markcore/src;)
	SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} markcore)
ENDIF()

# �������е����ӿ�
SET(LINK_ALL_LIBS   ${LINK_CUSTOM_LIBS})
MESSAGE(STATUS "SET LINK_ALL_LIBS = ${LINK_ALL_LIBS}")



####################################################################################################
MESSAGE(STATUS "\n**get_sourcefiles------------------------------------------------------------------")

# ��ȡ��ǰĿ¼������Ŀ¼�µ�����Դ�ļ�
SET(SRC "")
FOREACH(subdir ${SOURCE_DIRS})
    IF(EXISTS ${subdir}/res)
        IF(NOT DEFINED RES_TARGET_NAME)
            SET(RES_TARGET_NAME "-")
        ENDIF()
        add_res_files_target(${subdir}/res ${LIBS_PATH} each_res_clean_files ${RES_TARGET_NAME})
    ENDIF()
    AUX_SOURCE_DIRECTORY(${subdir} subdir_src)
	MESSAGE(STATUS "GET subdir_src = ${subdir_src}")
    SET(SRC ${SRC} ${subdir_src})
    SET(RES_CLEAN_FILES ${RES_CLEAN_FILES} ${each_res_clean_files})
    SET(subdir_src "")
    SET(each_res_clean_files "")
ENDFOREACH(subdir ${DIRS})
SET(SOURCESRCS ${SRC})
#MESSAGE(STATUS "SET SOURCESRCS = ${SOURCESRCS}")


#�������ָ����Դ�ļ� INCLUDE_SOURCE_FILES
SET(ALLSRCS ${SOURCESRCS} ${INCLUDE_SOURCE_FILES})

# ��ȡ����Դ�ļ�,��ͳһ������Ծ���·����ʾ���ļ���,�Ա�����ļ�����
SET(ALL_SOURCES "")
FOREACH(_allsrc ${ALLSRCS})
    get_filename_component(_allsrc_path ${_allsrc} PATH)
    get_filename_component(_allsrc_name ${_allsrc} NAME)
    # _allsrc_pathΪ�ձ�ʾ��ǰ·��
    IF("${_allsrc_path}" STREQUAL "")
        SET(ALL_SOURCES ${ALL_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/${_allsrc})
    ELSEIF("${_allsrc_path}" STREQUAL ".")
        SET(ALL_SOURCES ${ALL_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/${_allsrc_name})
    ELSEIF(IS_ABSOLUTE ${_allsrc_path})
        SET(ALL_SOURCES ${ALL_SOURCES} ${_allsrc})
    ELSE()
        SET(ALL_SOURCES ${ALL_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/${_allsrc})
    ENDIF()
ENDFOREACH()
#MESSAGE(STATUS "SET ALL_SOURCES = ${ALL_SOURCES}")



# ���˲���Ҫ������ļ�����Ҫ������ļ��ŵ�����OUTPUTS
MACRO(FILTER_OUT FILTERS INPUTS OUTPUTS)
   SET(FOUT "")
   FOREACH(INP ${INPUTS})
       SET(FILTERED 0)
       FOREACH(FILT ${FILTERS})
           IF(${FILTERED} EQUAL 0)
               IF("${FILT}" STREQUAL "${INP}")
                   SET(FILTERED 1)
               ENDIF("${FILT}" STREQUAL "${INP}")
           ENDIF(${FILTERED} EQUAL 0)
       ENDFOREACH(FILT ${FILTERS})
       IF(${FILTERED} EQUAL 0)
           SET(FOUT ${FOUT} ${INP})
       ENDIF(${FILTERED} EQUAL 0)
   ENDFOREACH(INP ${INPUTS})
   SET(${OUTPUTS} ${FOUT})
ENDMACRO(FILTER_OUT FILTERS INPUTS OUTPUTS)
MESSAGE(STATUS "MACRO(FILTER_OUT FILTERS INPUTS OUTPUTS)")


IF("${EXCLUDE_SOURCE_FILES}" STREQUAL "")
    SET(OUTPUTS ${ALL_SOURCES}
                ${THRIFT_GEN_CPP_HDRS}
                ${THRIFT_GEN_CPP_SRCS}
                ${IDL_HEADER_FILES})
ELSE()
    SET(ALL_EXCLUDE_SOURCE_FILES "")
    FOREACH(_exclude_source_file ${EXCLUDE_SOURCE_FILES})
        get_filename_component(_exclude_source_file_path ${_exclude_source_file} PATH)
        get_filename_component(_exclude_source_file_name ${_exclude_source_file} NAME)
        # Ϊ�ձ�ʾ��ǰ·��
        IF("${_exclude_source_file_path}" STREQUAL "")
            SET(ALL_EXCLUDE_SOURCE_FILES ${ALL_EXCLUDE_SOURCE_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/${_exclude_source_file})
        ELSEIF("${_exclude_source_file_path}" STREQUAL ".")
            set(ALL_EXCLUDE_SOURCE_FILES ${ALL_EXCLUDE_SOURCE_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/${_exclude_source_file_name})
        ELSEIF(IS_ABSOLUTE ${_exclude_source_file_path})
            SET(ALL_EXCLUDE_SOURCE_FILES ${ALL_EXCLUDE_SOURCE_FILES} ${_exclude_source_file})
        ELSE()
            SET(ALL_EXCLUDE_SOURCE_FILES ${ALL_EXCLUDE_SOURCE_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/${_exclude_source_file})
        ENDIF()
    ENDFOREACH()
    # ���˲���Ҫ������ļ�����Ҫ������ļ��ŵ�����OUTPUTS
    FILTER_OUT("${ALL_EXCLUDE_SOURCE_FILES}" "${ALL_SOURCES}" OUTPUTS)
    SET(OUTPUTS ${OUTPUTS}
                ${THRIFT_GEN_CPP_HDRS}
                ${THRIFT_GEN_CPP_SRCS}
                ${IDL_HEADER_FILES})
ENDIF()

MESSAGE(STATUS "SET ALL_EXCLUDE_SOURCE_FILES = ${ALL_EXCLUDE_SOURCE_FILES}")
MESSAGE(STATUS "SET OUTPUTS = ${OUTPUTS}")






####################################################################################################
MESSAGE(STATUS "\n**link_target----------------------------------------------------------------------")


#  ����
# �����������ɿ�Ϳ�ִ���ļ���·�����ڴ�ͳһ�������·����
# ���ò�ͬ������Ŀ��·��(���MSVC���Զ�����Debug��ReleaseĿ¼)

# First for the generic no-config case (e.g. with mingw)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LIBS_PATH})
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBS_PATH})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBS_PATH})

# Second, for multi-config builds (e.g. msvc)
FOREACH(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
	MESSAGE(STATUS "GET OUTPUTCONFIG = ${OUTPUTCONFIG}")
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${LIBS_PATH})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${LIBS_PATH})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${LIBS_PATH})
ENDFOREACH(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)


# link����
MESSAGE(STATUS "GET TARGET_TYPE = ${TARGET_TYPE}")

#�����RUNTIME�������ɿ�ִ���ļ�
IF("${TARGET_TYPE}" STREQUAL "RUNTIME")
	# win32 windows������Ҫ����WIN32ѡ��
	IF(WIN32)
		IF("${SUBSYSTEM}" STREQUAL "WINDOWS")
			SET(EXPECT_LINK_FLAG WIN32)
			MESSAGE(STATUS "SET EXPECT_LINK_FLAG = ${EXPECT_LINK_FLAG}")
		ENDIF()
		IF(NOT MSVC_VERSION)
			SET(CUSTOM_LDFLAGS "${CUSTOM_LDFLAGS} /MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")
			MESSAGE(STATUS "SET CUSTOM_LDFLAGS = ${CUSTOM_LDFLAGS}")
		ENDIF()
	ENDIF()
	
	#�����RUNTIME,�����ɿ�ִ���ļ�
	LINK_DIRECTORIES(${LIBS_PATH})
	ADD_EXECUTABLE(${TARGET_NAME} ${EXPECT_LINK_FLAG} ${OUTPUTS})
	TARGET_LINK_LIBRARIES(${TARGET_NAME} ${LINK_ALL_LIBS})
	MESSAGE(STATUS "TARGET_LINK_LIBRARIES(${TARGET_NAME} ${LINK_ALL_LIBS})")
	
	#RUNTIME
	install_target(RUNTIME ${TARGET_NAME} .)
	
	#debuginfo
	MESSAGE(STATUS "GET NEED_DEBUGINFO = ${NEED_DEBUGINFO}")
	IF(NEED_DEBUGINFO)
		SET(TARGET_FULL_NAME ${TARGET_NAME})
		ADD_CUSTOM_COMMAND(TARGET ${TARGET_NAME}
						   COMMAND objcopy --only-keep-debug ${TARGET_FULL_NAME} ${TARGET_FULL_NAME}.debug
						   COMMAND objcopy --strip-debug ${TARGET_FULL_NAME}
						   COMMAND objcopy --add-gnu-debuglink=${TARGET_FULL_NAME}.debug ${TARGET_FULL_NAME}
						   WORKING_DIRECTORY ${LIBS_PATH})
		LIST(APPEND DEBUGINFO_CLEAN_FILES ${LIBS_PATH}/${TARGET_FULL_NAME}.debug)
		install_files(debuginfo ${LIBS_PATH}/${TARGET_FULL_NAME}.debug)
	ENDIF()
	
# ���ӳ�һ����̬��
ELSEIF("${TARGET_TYPE}" STREQUAL "LIBRARY")
	LINK_DIRECTORIES(${LIBS_PATH})
	ADD_LIBRARY(${TARGET_NAME} SHARED ${OUTPUTS})
	TARGET_LINK_LIBRARIES(${TARGET_NAME} ${LINK_ALL_LIBS})
	MESSAGE(STATUS "TARGET_LINK_LIBRARIES(${TARGET_NAME} ${LINK_ALL_LIBS})")
	
	#LIBRARY
	IF(WIN32)
		# Windows�µĶ�̬�ⱻ��Ϊ��RUNTIME����
		install_target(RUNTIME ${TARGET_NAME} .)
		install_target(ARCHIVE ${TARGET_NAME} .)
	ELSE()
		install_target(LIBRARY ${TARGET_NAME} .)
	ENDIF()

	#debuginfo
	MESSAGE(STATUS "GET NEED_DEBUGINFO = ${NEED_DEBUGINFO}")
	IF(NEED_DEBUGINFO)
		SET(TARGET_FULL_NAME ${CMAKE_SHARED_LIBRARY_PREFIX}${TARGET_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})
		ADD_CUSTOM_COMMAND(TARGET ${TARGET_NAME}
						   COMMAND objcopy --only-keep-debug ${TARGET_FULL_NAME} ${TARGET_FULL_NAME}.debug
						   COMMAND objcopy --strip-debug ${TARGET_FULL_NAME}
						   COMMAND objcopy --add-gnu-debuglink=${TARGET_FULL_NAME}.debug ${TARGET_FULL_NAME}
						   WORKING_DIRECTORY ${LIBS_PATH})
		LIST(APPEND DEBUGINFO_CLEAN_FILES ${LIBS_PATH}/${TARGET_FULL_NAME}.debug)
		install_files(debuginfo ${LIBS_PATH}/${TARGET_FULL_NAME}.debug)
	ENDIF()
	
# ���ӳ�һ����̬��
ELSEIF("${TARGET_TYPE}" STREQUAL "ARCHIVE")
	LINK_DIRECTORIES(${LIBS_PATH})
	ADD_LIBRARY(${TARGET_NAME} STATIC ${OUTPUTS})
	TARGET_LINK_LIBRARIES(${TARGET_NAME} ${LINK_ALL_LIBS})
	MESSAGE(STATUS "TARGET_LINK_LIBRARIES(${TARGET_NAME} ${LINK_ALL_LIBS})")
	install_target(ARCHIVE ${TARGET_NAME} .)
ELSEIF("${TARGET_TYPE}" STREQUAL "")
	#���û��ָ��������
	MESSAGE(FATAL_ERROR "Must have a target type")
ENDIF()



# �Ƿ�����RES_FILES
MESSAGE(STATUS "GET RES_FILES = ${RES_FILES}")
IF(NOT "${RES_FILES}" STREQUAL "")
	ADD_CUSTOM_TARGET(${TARGET_NAME}_res ALL DEPENDS ${RES_FILES})
	ADD_DEPENDENCIES(${TARGET_NAME} ${TARGET_NAME}_res)
	MESSAGE(STATUS "ADD_DEPENDENCIES(${TARGET_NAME})")
	MESSAGE(STATUS "ADD_DEPENDENCIES(${TARGET_NAME}_res)")
ENDIF()


# �Ƿ�����target�汾
MESSAGE(STATUS "GET TARGET_VERSION = ${TARGET_VERSION}")
IF(NOT "${TARGET_VERSION}" STREQUAL "")
	SET_TARGET_PROPERTIES(${TARGET_NAME} PROPERTIES VERSION ${TARGET_VERSION})
ENDIF()


# �Զ������Ӳ���  
MESSAGE(STATUS "GET CUSTOM_LDFLAGS = ${CUSTOM_LDFLAGS}")
IF (DEFINED CUSTOM_LDFLAGS) 
	SET_TARGET_PROPERTIES(${TARGET_NAME} PROPERTIES LINK_FLAGS ${CUSTOM_LDFLAGS}) 
ENDIF ()



####################################################################################################
MESSAGE(STATUS "\n**add make clean-------------------------------------------------------------------")

# ��ӱ���IDL�ļ�����ļ���mo�ļ��͵�cleanѡ��Ա�clean�������
SET(ADDITIONAL_CLEAN_FILES ${RES_CLEAN_FILES}; ${IDL_CLEAN_FILES}; ${THRIFT_CLEAN_FILES}; ${DEBUGINFO_CLEAN_FILES})
MESSAGE(STATUS "SET ADDITIONAL_CLEAN_FILES = ${ADDITIONAL_CLEAN_FILES}")
SET_DIRECTORY_PROPERTIES(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${ADDITIONAL_CLEAN_FILES}")



####################################################################################################
MESSAGE(STATUS "\n**check-----------------------------------------------------------------------------")

MESSAGE(STATUS "GET CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
MESSAGE(STATUS "GET CMAKE_SYSTEM = ${CMAKE_SYSTEM}")
MESSAGE(STATUS "GET CMAKE_SYSTEM_VERSION = ${CMAKE_SYSTEM_VERSION}")
MESSAGE(STATUS "GET CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")
MESSAGE(STATUS "GET PROJECT_NAME = ${PROJECT_NAME}")
MESSAGE(STATUS "GET CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "GET TARGET_TYPE = ${TARGET_TYPE}")
MESSAGE(STATUS "GET CMAKE_BUILD_VERSION = ${CMAKE_BUILD_VERSION}")
MESSAGE(STATUS "GET PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")

MESSAGE(STATUS "GET CMAKE_CXX_FLAGS_DEBUG = ${CMAKE_CXX_FLAGS_DEBUG}")
MESSAGE(STATUS "GET CMAKE_CXX_FLAGS_RELEASE = ${CMAKE_CXX_FLAGS_RELEASE}")

MESSAGE(STATUS "GET CMAKE_EXE_LINKER_FLAGS = ${CMAKE_EXE_LINKER_FLAGS}")
MESSAGE(STATUS "GET CMAKE_EXE_LINKER_FLAGS_RELEASE = ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")

MESSAGE(STATUS "GET CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")
MESSAGE(STATUS "GET CMAKE_SHARED_LINKER_FLAGS = ${CMAKE_SHARED_LINKER_FLAGS}")
MESSAGE(STATUS "GET CMAKE_SHARED_LINKER_FLAGS_RELEASE = ${CMAKE_SHARED_LINKER_FLAGS_RELEASE}")
MESSAGE(STATUS "GET CMAKE_STATIC_LINKER_FLAGS = ${CMAKE_STATIC_LINKER_FLAGS}")

####################################################################################################
MESSAGE(STATUS "\n**end.cmake end-------------------------------------------------------------------")
MESSAGE(STATUS "")



