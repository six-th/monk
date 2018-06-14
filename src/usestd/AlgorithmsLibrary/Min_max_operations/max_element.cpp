﻿/***************************************************************************************************
Author:liu.hao

Time:2018-6

info:
    
***************************************************************************************************/

#include <mkheaders.h>
#include <gtest/gtest.h>

//返回区间内的最大元素 
TEST(MinMax, max_element)
{
    std::vector<int> v{ 3, 1, -14, 1, 5, 9 }; 
    MK_PRINT_MSG("result = %d", *std::max_element(v.begin(),v.end()));
    
    MK_PRINT_MSG("result = %d", *std::max_element(v.begin(),v.end(), std::greater<int>()));
}
