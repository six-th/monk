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

Time:2018-6

info:
    
***************************************************************************************************/

#include <mkheaders.h>
#include <gtest/gtest.h>

//检查范围 [first, last) 中的元素是否为最大堆。  
TEST(Heap, is_heap)
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
    
    std::make_heap(v.begin(), v.end());
    for_each(v.begin(),v.end(),[](const int& elem){MK_PRINT_MSG("%d", elem);});
    
    bool ret = std::is_heap(v.begin(), v.end());
    MK_PRINT_MSG("ret = %d", ret);
}

//检查范围 [first, last) 中的元素是否为最大堆。  
TEST(Heap, is_heap_2)
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
    
    std::make_heap(v.begin(), v.end(),std::greater<int>());
    for_each(v.begin(),v.end(),[](const int& elem){MK_PRINT_MSG("%d", elem);});
    
    bool ret = std::is_heap(v.begin(), v.end(),std::greater<int>());
    MK_PRINT_MSG("ret = %d", ret);
}






