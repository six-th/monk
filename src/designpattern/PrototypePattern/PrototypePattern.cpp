/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	ԭ��ģʽ
	ԭ��ģʽ�ṩ�����Ҹ��ƵĹ��ܣ�����˵�¶���Ĵ�������ͨ�����ж�����д�����
	ԭ��ģʽ�ṩ��һ��ͨ���Ѵ��ڶ�������¶��󴴽��Ľӿڣ�Clone����
	Clone()ʵ�ֺ;����ʵ��������أ��� C++�����ǽ�ͨ���������캯��ʵ��֮�� 
	
	�Աȣ�
	ԭ��ģʽͨ������ԭ�ͣ�ԭ�ͣ�������¶��󴴽��Ĺ��ܣ�����ԭ�ͱ������"���󹤳�"����Ϊ�ܹ��������󣩣�
	ʵ����ԭ��ģʽ�� Builder ģʽ��AbstractFactory ģʽ����ͨ��һ���ࣨ����ʵ������ר�Ÿ������Ĵ����������������󣩣�
	����֮��������ǣ�
	Builder ģʽ���ڸ��Ӷ����һ��������������ֱ�ӷ��ض��󣩣�
	AbstractFactory ģʽ���ڲ�������໥������Ķ���
	��ԭ��ģʽ���ڴ��������Լ��������ࡣ
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace PrototypePattern {
// Prototype
class Prototype 
{
public:
	virtual Prototype* Clone() = 0;
	virtual ~Prototype() { }
};

class ConcretePrototype :public Prototype 
{
public:
	ConcretePrototype() { }

	ConcretePrototype(const ConcretePrototype&cp) 
	{
		cout << "ConcretePrototype copy..." << endl;
	}

	Prototype* Clone() 
	{
		return new ConcretePrototype(*this);
	}
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace PrototypePattern;
class ut_PrototypePattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F(ut_PrototypePattern, Operation)
{
	Prototype *prototype = new ConcretePrototype();
	cout << prototype << endl;
	
	Prototype* prototype1 = prototype->Clone();
	cout << prototype1 << endl;
	
	Prototype* prototype2 = prototype->Clone();
	cout << prototype2 << endl;

	delete prototype;
	delete prototype1;
	delete prototype2;
}