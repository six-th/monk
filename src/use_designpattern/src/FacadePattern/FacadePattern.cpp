/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	���ģʽ
	ʵ���������ϵͳ������Ҳ�����ػ����������������
	������ʵ����һЩ�ӿڣ�ģ�飩������Щ�ӿڣ�ģ�飩���ֲ��ڼ������У����� A �� B��C��D����
	A ��ʵ����һЩ�ӿڣ�B ��ʵ��һЩ�ӿڣ����� A ����һ������ģ�飬B��C��D ������һЩ����ģ�飩��
	Ȼ����Ŀͻ�����Ա��ʹ������ƵĿ�����Ա��ֻ�к��ٵ�Ҫ֪����Ĳ�ͬ�ӿڵ��������Ǹ�����ʵ�ֵģ�
	�������ֻ����򵥵������� A��D ����Ľӿڣ���������֪����Щ�ӿ�������ʵ�ֵġ�
	
	���ģʽ���뷨��˼·��ʵ�ֶ��ǳ��򵥣�������˼��ȴ�Ƿǳ�������ġ�
	����������ģʽ��ʵ�ʵĿ��������Ҳ��Ӧ����㡢����ģʽ֮һ��
	
	�Աȣ�
	���ģʽ�ڸ߲��ṩ��һ��ͳһ�Ľӿڣ�������ϵͳ��
	���ģʽ�л�����һ��ģʽ�н���Ҳ����������Ƶĵط���
	�����н�����ҪĿ���Ƕ����ķ��ʵĽ��ͨѶʱ���Э�飩��
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace FacadePattern {
class SubSystem1 
{
public:
	void Operation() {cout << "SubSystem1 operation..." << endl;}
};

class SubSystem2 
{
public:
	void Operation() {cout << "SubSystem2 operation..." << endl;}
};

class Facade 
{
public:
	Facade() 
	{
		_sub1 = new SubSystem1();
		_sub2 = new SubSystem2();
	}
	
	~Facade() 
	{
		delete _sub1;
		delete _sub2;
	}

	void OperationWrapper() 
	{
		_sub1->Operation();
		_sub2->Operation();
	}
private:
	SubSystem1 *_sub1;
	SubSystem2 *_sub2;
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//

using namespace FacadePattern;

class ut_FacadePattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_FacadePattern, Operation)
{
	Facade *facade = new Facade();
	facade->OperationWrapper();

	delete facade;
}