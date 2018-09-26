MESSAGE(STATUS "find wxWidgets libs...")

set(SUBSYSTEM WINDOWS)

#Ĭ��ʹ�ö�̬��,�ϲ������ǰ�����Ա�ʹ�þ�̬��
IF("${WX_DYNAMIC_LINK}" STREQUAL "")
    set(WX_DYNAMIC_LINK ON)
ENDIF()

SET(WX_PATH ${MONK_PATH}/3rd_Party/wxwidgets)

#debug��صĺ�
IF("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    #begin.cmake��debuging����Ϊ0,�����޷���ȷ����wx��.lib���ļ�
    ADD_DEFINITIONS(-D__WXMSW__ -D__WXDEBUG__ -D_HAS_ITERATOR_DEBUGGING=1)
    
    IF("${WX_DYNAMIC_LINK}" STREQUAL "ON")
        #��̬����ʹ��dll
        MESSAGE(STATUS "[debug] using .dll...")
        SET(WXLIBS_PATH ${WX_PATH}/build_target)
        ADD_DEFINITIONS(-DWXUSINGDLL -DwxMONOLITHIC=1 -DwxNO_GL_LIB)
        INCLUDE_DIRECTORIES(${WXLIBS_PATH}/include; ${WXLIBS_PATH}/include/msvc)
        link_directories(${WXLIBS_PATH}/lib/vc_x64_dll)
        
        IF("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
            seek_deps_file_no_install(${LIBS_PATH} ${WXLIBS_PATH}/lib/vc_x64_dll wxmsw312ud_vc_x64_custom.dll)
        ENDIF ()
    ELSE()
        #��̬����ʹ��lib
        MESSAGE(STATUS "[debug] using .lib...")
        SET(WXLIBS_PATH ${WX_PATH}/wxWidgets)
        INCLUDE_DIRECTORIES(${WXLIBS_PATH}/include;${WXLIBS_PATH}/include/msvc)
        link_directories(${WXLIBS_PATH}/lib/vc_x64_lib)
        link_libraries(
            wxbase31ud.lib
            wxbase31ud_net.lib
            wxbase31ud_xml.lib
            wxexpatd.lib
            wxjpegd.lib
            wxmsw31ud_adv.lib
            wxmsw31ud_aui.lib
            wxmsw31ud_core.lib
            wxmsw31ud_gl.lib
            wxmsw31ud_html.lib
            wxmsw31ud_media.lib
            wxmsw31ud_propgrid.lib
            wxmsw31ud_qa.lib
            wxmsw31ud_ribbon.lib
            wxmsw31ud_richtext.lib
            wxmsw31ud_stc.lib
            wxmsw31ud_webview.lib
            wxmsw31ud_xrc.lib
            wxpngd.lib
            wxregexud.lib
            wxscintillad.lib
            wxtiffd.lib
            wxzlibd.lib
        )
        #��ѡ��̬��
        #"kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" 
        # "shell32.lib" "ole32.lib" "oleaut32.lib"  "uuid.lib" "odbc32.lib" "odbccp32.lib"
    ENDIF()
    
#release
ELSE()
    ADD_DEFINITIONS(-D__WXMSW__)
    
    IF("${WX_DYNAMIC_LINK}" STREQUAL "ON")
        #todo
    ELSE()
        #��̬����ʹ��lib
        MESSAGE(STATUS "[release] using .lib...")
        SET(WXLIBS_PATH ${WX_PATH}/wxWidgets)
        INCLUDE_DIRECTORIES(${WXLIBS_PATH}/include;${WXLIBS_PATH}/include/msvc)
        link_directories(${WXLIBS_PATH}/lib/vc_x64_lib)
        link_libraries(
            wxbase31u.lib
            wxbase31u_net.lib
            wxbase31u_xml.lib
            wxexpat.lib
            wxjpeg.lib
            wxmsw31u_adv.lib
            wxmsw31u_aui.lib
            wxmsw31u_core.lib
            wxmsw31u_gl.lib
            wxmsw31u_html.lib
            wxmsw31u_media.lib
            wxmsw31u_propgrid.lib
            wxmsw31u_qa.lib
            wxmsw31u_ribbon.lib
            wxmsw31u_richtext.lib
            wxmsw31u_stc.lib
            wxmsw31u_webview.lib
            wxmsw31u_xrc.lib
            wxpng.lib
            wxregexu.lib
            wxscintilla.lib
            wxtiff.lib
            wxzlib.lib
        )
    ENDIF()
    
ENDIF()












