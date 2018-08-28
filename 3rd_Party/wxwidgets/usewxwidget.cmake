MESSAGE(STATUS "find wxWidgets libs...")

#deps·��
SET(WXLIBS_PATH ${ABDEPS}/wxWidgets/build_target)

#��Ӻ궨��
ADD_DEFINITIONS(-DWXUSINGDLL -DwxMONOLITHIC=1 -DwxNO_GL_LIB)

#����ͷ�ļ�·��
INCLUDE_DIRECTORIES(${WXLIBS_PATH}/include;
                    ${WXLIBS_PATH}/include/msvc)

                    
#���þ�̬��(wxmsw31ud.lib)·��
link_directories(${WXLIBS_PATH}/lib/vc_x64_dll)

#copy��̬��(wxmsw312u_vc_x64_custom.dll)������Ŀ¼
IF("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    SET(WXLIBS_DLL_NAME wxmsw312ud_vc_x64_custom.dll)
ELSE ()
    SET(WXLIBS_DLL_NAME wxmsw312u_vc_x64_custom.dll)
ENDIF ()
seek_deps_file_no_install(${LIBS_PATH}  ${WXLIBS_PATH}/lib/vc_x64_dll ${WXLIBS_DLL_NAME})
#seek_deps_library(${LIBS_PATH} ${WXLIBS_PATH}/lib/vc_x64_dll ${WXLIBS_DLL_NAME})
