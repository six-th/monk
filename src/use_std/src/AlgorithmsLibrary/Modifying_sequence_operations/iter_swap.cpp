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

//交换两个迭代器所指向的元素 
TEST(MSQ, iter_swap)
{
    vector<int> v{3,5,7,1,4,6,9,3,6};
    //选择排序
    for(auto iter = v.begin(); iter != v.end(); ++iter) {
        std::iter_swap(iter, std::min_element(iter, v.end()) );
    }
    for (auto elem : v) {
        MK_PRINT_MSG("n = %d", elem);
    }
}