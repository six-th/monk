﻿/***************************************************************************************************
LICENSE:
    Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
Author:liu.hao(33852613@163.com)

Time:2021-1

info:

***************************************************************************************************/
#ifdef __WINDOWS__
    #include <io.h>//for access()
#endif
#include <fstream>

#include <mkheaders.h>
#include "utility/mkTime.h"
#include "utility/mkSourceLocation.h"
#include"mkTrace.h"

mkTrace::mkTrace(const std::string& moduleName)
    : _moduleName(moduleName)
{
    #ifdef __WINDOWS__
        _fileName = "C:\\mk\\mk.trace";
    #else
        _fileName = "/mk/mk.trace";
    #endif
}

mkTrace::~mkTrace()
{
}

bool 
mkTrace::Enable()
{
    //检查trace是否打开,未打开直接返回
    //int access(const char* filename, int amode); amode为0表示检查文件的存在性，如果文件存在，返回0，不存在，返回-1
    bool fileExist = (access(_fileName.c_str(), 0) == 0);
    return fileExist;
}

void 
mkTrace::Output(const char* file, int line, const char* func, const char* msg)
{
    shared_ptr<char> buf = mkFormat::shared("[%s] [%s]: (%s:%d) %s() %s", 
        _moduleName.c_str(), mkTime::GetCurrentTimeStr().c_str(), mkSourceLocation::file_name(file), line, func, msg);
    
    //todo:性能待优化:缓存+异步sync
    fstream fs (_fileName, fstream::app | fstream::out | fstream::ate);//追加写
    fs << buf.get() << endl;
    fs.close ();
}