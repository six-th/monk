/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	�н���ģʽ
	�н���ģʽ�ṩ�������Ľ�����ͨѶ��װ��һ�����У�
	����������ͨ�Ų�������ȥ���������ã���󽵵���ϵͳ�ĸ������ܣ��˽�һ�������ܱ�������Ϥ n ������Ҫ�ã���
	�����н���ģʽ��������ϵͳ����������ϡ�
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <string>
using namespace std;

namespace MediatorPattern {
class Person;

class Mediator 
{
public:
	virtual void Send(const string& msg, Person* person) = 0;
	virtual ~Mediator() { }
	
	void BuildRelation(Person *a, Person *b) 
	{
		m_a = a;
		m_b = b;
	}

protected:
	Person *m_a;
	Person *m_b;
};

class ConcreteMediator :public Mediator 
{
public:
	void Send(const string& msg, Person* person) 
	{
		if (person == m_a) {
			cout << msg << "--Mediator--PersonB" << endl;
		}
		else if (person == m_b) {
			cout << msg << "--Mediator--PersonA" << endl;
		}
	}
};

class Person 
{
public:
	Person(Mediator*md):_md(md) { }
	virtual void SendMessage(const string& msg) = 0;
	virtual ~Person() { }
protected:
	Mediator* _md;
};

class ConcretePersonA :public Person 
{
public:
	ConcretePersonA(Mediator* md):Person(md) { }

	void SendMessage(const string& msg) 
	{
		_md->Send(msg, this);
	}
};

class ConcretePersonB :public Person 
{
public:
	ConcretePersonB(Mediator* md):Person(md) { }

	void SendMessage(const string& msg) 
	{
		_md->Send(msg, this);
	}
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace MediatorPattern;
class ut_MediatorPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_MediatorPattern, Operation)
{
	/*
	�н���ģʽ��һ�ֺ����ò��Һܳ��õ�ģʽ��
	��ͨ����������ͨ�ŷ�װ��һ�����У�����Զ��ͨ��ת��Ϊһ�Զ��ͨ�ţ�������ϵͳ�ĸ����ԡ�
	
	�н��߻����ϵͳ��������ԣ�
	ͨ�� Mediator������ Colleague �Ͳ���ά������ͨ�ŵĶ����ͨ��Э�飬������ϵͳ������ԣ��н��ߺ͸��� Colleague �Ϳ����໥�������޸��ˡ�
	
	�н���ģʽ����һ�����������ص���ǽ����Ƽ��У����е��ŵ���Ǳ��ڹ���Ҳ��ʽ������ OO ����е�ÿ�����ְ��Ҫ��һ�ͼ��е�ԭ��
	*/
	Mediator *mediator = new ConcreteMediator();
	Person *personA = new ConcretePersonA(mediator);
	Person *personB = new ConcretePersonB(mediator);

	mediator->BuildRelation(personA, personB);
	personA->SendMessage("PersonA");
	personB->SendMessage("PersonB");

	delete personA;
	delete personB;
	delete mediator;
}
