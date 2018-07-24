﻿/***************************************************************************************************
Author:liu.hao

Time:2018-6

info:
    查找彼此相邻的两个相同（或其它的关系）的元素 
    返回值:指向首对等同元素的首个元素的迭代器，若找不到这种元素，则返回 last 。 
***************************************************************************************************/

#include <mkheaders.h>
#include <gtest/gtest.h>


TEST(NMSQ, adjacent_find)
{
    std::vector<int> v{0, 1, 2, 3, 40, 40, 41, 41, 5};
    auto ret = std::adjacent_find(v.begin(), v.end());
    if(ret == v.end()) {
        MK_PRINT_MSG("not found.");
    }
    else {
        MK_PRINT_MSG("found elem at %d", std::distance(v.begin(), ret));
    }
}

TEST(NMSQ, adjacent_find2)
{
    std::vector<int> v{0, 1, 2, 3, 40, 40, 41, 41, 5};
    auto ret = std::adjacent_find(v.begin(), v.end(), std::greater<int>());
    if(ret == v.end()) {
        MK_PRINT_MSG("not found.");
    }
    else {
        MK_PRINT_MSG("found elem at %d", std::distance(v.begin(), ret));
    }
}