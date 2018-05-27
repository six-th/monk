/***************************************************************************************************
Author:liu.hao

Time:2017-6

info:

***************************************************************************************************/

#include <mkheaders.h>
#include <gtest/gtest.h>
#include "mkString.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// ncEnvironment
//
//ȫ���¼����˴�����ı���������ȫ��ʹ��
class ncEnvironment : public testing::Environment
{
public:
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// main
//
int main(int argc, char** argv)
{
	// ��ȡ�������
	if(argc == 1) {
		wprintf(_T(" Error:Invalid arguments! 									\
						\n Please use the following way: 								\
						\n    ./test --gtest_filter=aaaUT.*								\
						\n or:./test --gtest_filter=aaaUT.*:bbbUT.*						\
						"));
		return 0;
	}
	
	try {
		testing::AddGlobalTestEnvironment(new ncEnvironment());
		testing::InitGoogleTest(&argc, argv); 
		
		int ret = RUN_ALL_TESTS ();
		return ret;
	}
	catch (...) {
		wprintf (_T("Test Error: Unknown."));
		return 1;
	}
	
	return 0;
}