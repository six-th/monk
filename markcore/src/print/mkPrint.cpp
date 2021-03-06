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
#include <iostream>
#include <mkheaders.h>
#include "utility/mkTime.h"
#include "utility/mkSourceLocation.h"
#include"mkPrint.h"

mkPrint::mkPrint(const std::string& moduleName)
    : _moduleName(moduleName)
{

}

mkPrint::~mkPrint()
{
}

void 
mkPrint::Output(const char* file, int line, const char* func, const char* msg)
{
    shared_ptr<char> buf = mkFormat::shared("[%s] [%s]: (%s:%d) %s() %s", 
        _moduleName.c_str(), mkTime::GetCurrentTimeStr().c_str(), mkSourceLocation::file_name(file), line, func, msg);
    
    std::cout<<buf.get()<<endl;//将消息打印到标准输出
}