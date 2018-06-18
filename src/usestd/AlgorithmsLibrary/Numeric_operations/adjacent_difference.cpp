﻿/***************************************************************************************************
Author:liu.hao

Time:2018-6

info:
 
***************************************************************************************************/

#include <mkheaders.h>
#include <gtest/gtest.h>
#include <numeric>


//计算 [first, last) 范围中每对相邻元素的第二个和第一个的差，
//并写入它们到始于 d_first + 1 的范围。写入不修改的 *first 副本到 *d_first 。  
TEST(Numeric, adjacent_difference)
{
    //默认实现——二个项之间的差
    std::vector<int> v{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    for_each(v.begin(),v.end(),[](auto& elem){MK_PRINT_MSG("%d", elem);});
    cout<<endl;
    
    //斐波那契,列表中下一项是当前迭代的结果
    v = std::vector<int>(10);
    v[0] = 1;
    std::adjacent_difference(v.begin(), v.end() - 1, v.begin() + 1, std::plus<int>());
    for_each(v.begin(),v.end(),[](auto& elem){MK_PRINT_MSG("%d", elem);});
}
