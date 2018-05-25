/***************************************************************************************************
Author:liu.hao

Time:2018-4

info:

***************************************************************************************************/
#include <gtest/gtest.h>

int main(int argc, char** argv) 
{
    #ifdef __WINDOWS__
        //�л��������汾,�Լ��ر�һЩ�Ż�ѡ��,ֻ��linux����Ч
        static_assert(false, "windows is not supported.");
    #endif
    
    
    // ��ȡ�������
    if(argc == 1) {
        printf("eg: ./test --gtest_filter=aaaUT.*    or: ./test --gtest_filter=aaaUT.*:bbbUT.*\n");
        return 0;
    }
    
    testing::InitGoogleTest(&argc, argv); 
    int ret = RUN_ALL_TESTS ();
    return ret;
}