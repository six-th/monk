IF(WIN32)
    include_directories(${MK_PATH}/3rd_Party/leveldb/leveldb/include)
    seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/__build/leveldb/${CMAKE_BUILD_TYPE} leveldb)
ELSE()
    include_directories(${MK_DEPS_PKGS}/leveldb/include)
    seek_deps_library(${LIBS_PATH} ${MK_DEPS_PKGS}/leveldb/lib64 leveldb)
ENDIF()
SET(LINK_CUSTOM_LIBS ${LINK_CUSTOM_LIBS} leveldb)