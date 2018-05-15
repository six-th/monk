/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	������ģʽ
	������ģʽ������һ���ŵ���Ǹ�ϵͳ����������ԣ�
	����ķ�������ȫ����֪��������ᱻ�ĸ�Ӧ�����������ؽ�����ϵͳ������ԡ�
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace ChainOfResponsibilityPattern {

class Handle 
{
public:
	virtual ~Handle() { }
	virtual void HandleRequest() = 0;
	
	void SetSuccessor(Handle *succ) {_succ = succ;}
	Handle* GetSuccessor()const {return _succ;}

protected:
	Handle() { _succ = nullptr; }
	Handle(Handle* succ) {_succ = succ;}
private:
	Handle* _succ;
};

class ConcreteHandleA :public Handle 
{
public:
	ConcreteHandleA() { }
	ConcreteHandleA(Handle* succ):Handle(succ) {}

	void HandleRequest() {
		if (this->GetSuccessor() != 0) {
			cout << "ConcreteHandleA--Successor" << endl;//�Ѵ���Ȩ����̽ڵ�
			GetSuccessor()->HandleRequest();
		}
		else {
			cout << "ConcreteHandleA::HandleRequest" << endl;//û�к�̽ڵ㣬��Ҫ�Լ�����
		}
	}
};

class ConcreteHandleB :public Handle 
{
public:
	ConcreteHandleB() { }
	ConcreteHandleB(Handle* succ):Handle(succ) {}

	void HandleRequest() {
		if (this->GetSuccessor() != 0) {
			cout << "ConcreteHandleB--Successor" << endl;////�Ѵ���Ȩ����̽ڵ�
			GetSuccessor()->HandleRequest();
		}
		else {
			cout << "ConcreteHandleB::HandleRequest" << endl;//û�к�̽ڵ㣬��Ҫ�Լ�����
		}
	}
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//

using namespace ChainOfResponsibilityPattern;

class ut_ChainOfResponsibilityPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_ChainOfResponsibilityPattern, Operation)
{
	//ConcreteHandleA �Ķ���h1ӵ��һ����� ConcreteHandleB �Ķ��� h2,
	//��һ��������ʱ��h1 ��鿴�Լ��к�̣�
	//���� h1 ֱ�ӽ����󴫵ݸ����� h2 ���д���
	//h2 ��Ϊû�к�̣���������ʱ�򣬾�ֻ���Լ��ṩ��Ӧ�ˡ�
	Handle *h1 = new ConcreteHandleA();
	Handle *h2 = new ConcreteHandleB();
	h1->SetSuccessor(h2);
	
	h1->HandleRequest();
	h2->HandleRequest();

	delete h1;
	delete h2;
}
