/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	��Ԫģʽ
	��Ԫģʽ��Flyweight������ά��һ������ʵ���Ĺ���أ�ʵ�ֶ���ʵ���Ĺ���ͻ������á�
	
	��Ԫģʽ��ʵ�ֹ�������Ҫ��ҪΪ��������ṩһ����ŵ�"�ֿ�"������أ���
	������ͨ�� C++ STL �� Vector ��������Ȼ��ǣ�浽 STL ��̵�һЩ���⡣
	����Ӧ��ע��ľ��ǶԶ���"�ֿ�"������أ��Ĺ�����ԣ����ҡ�����ȣ���
	������ͨ��ֱ�ӵ�˳�����ʵ�ֵģ���Ȼ���ǿ���ʹ������������Ч���������ԣ�
	���� Hash ��Ĺ�����ԣ���ʱ��Щϸ���Ѿ�������Ԫģʽ����Ҫ������ˡ�
	
	�Աȣ�
	������״̬ģʽ�Ͳ���ģʽ�л�����ܶ�Ķ���������ǿ���ͨ����Ԫģʽ�����������⡣
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace FlyweightPattern {

class Flyweight 
{
public:
	Flyweight(string state)
		:_state(state) 
	{
	}
	virtual ~Flyweight() { }
	
	virtual void Operation(const string&state) { }
	string GetState()const { return _state; }
private:
	string _state;
};

class ConcreteFlyweight :public Flyweight 
{
public:
	ConcreteFlyweight(string state)
		:Flyweight(state) 
	{
		cout << "ConcreteFlyweight Build..." << state << endl;
	}

	void Operation(const string& state) 
	{
		cout << "ConcreteFlyweight " << GetState() << " \\ " << state << endl;
	}
};

//lyweightFactory ӵ��һ�������洢�����"�ֿ�"�����߽ж���أ���
//GetFlyweight������Ϣ�����������еĶ�������Ѿ�������ֱ�ӷ��ظ� Client�����򴴽�һ���µĶ��󷵻ظ� Client��
class FlyweightFactory 
{
public:
	Flyweight *GetFlyweight(std::string key) 
	{
		for (auto fly : _flys) {
			if (fly->GetState() == key) {
				cout << "already created by users..." << endl;
				return fly;
			}
		}
		Flyweight *fn = new ConcreteFlyweight(key);
		_flys.push_back(fn);
		return fn;
	}
private:
	std::vector<Flyweight*> _flys;
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//

using namespace FlyweightPattern;

class ut_FlyweightPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_FlyweightPattern, Operation)
{
	FlyweightFactory *fc = new FlyweightFactory();
	
	//���ǿ���Ϊ�������״̬��Ϊ"�ⲿ״̬"��"�ڲ�״̬"��
	//�����Ա���������仯����״̬��Ϊ�ڲ�״̬�洢�ڶ����У����������:hello��world
	//���ⲿ�������ǿ������ʵ���ʱ���ⲿ������Ϊ�������ݸ�����;���������:aaa,bbb,ccc
	Flyweight *fw1 = fc->GetFlyweight("hello");
	fw1->Operation("aaa");
	
	Flyweight *fw2 = fc->GetFlyweight("world");
	fw2->Operation("bbb");
	
	Flyweight *fw3 = fc->GetFlyweight("hello");
	fw3->Operation("ccc");
	
	delete fw1;
	delete fw2;
	//delete fw3;
	delete fc;
}
