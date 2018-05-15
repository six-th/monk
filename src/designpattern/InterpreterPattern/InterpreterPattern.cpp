/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	������ģʽ
	һЩӦ���ṩ���ڽ���Build-In���Ľű����ߺ����������û����Զ��������ܹ���ϵͳ�н��еĲ�����
	������ģʽ��Ŀ�ľ���ʹ��һ��������Ϊ�û��ṩһ��һ�Ŷ������Ե��﷨��ʾ�Ľ�������
	Ȼ��ͨ����������������������еľ��ӡ�
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <string>
using namespace std;

namespace InterpreterPattern {
	
class Context 
{ 
};

class Expression 
{
public:
	virtual ~Expression() { }
	virtual void Interpret(const Context& c) = 0;
};

class TerminalExpression :public Expression 
{
public:
	TerminalExpression(const string& statement) 
	{
		_statement = statement;
	}

	void Interpret(const Context& c) 
	{
		cout << this->_statement << " -- TerminalExpression" << endl;
	}

private:
	string _statement;
};

class NonterminalExpression :public Expression 
{
public:
	NonterminalExpression(Expression* expression, int times) 
	{
		_expression = expression;
		_times = times;
	}

	void Interpret(const Context& c) 
	{
		for (int i = 0; i < _times; i++) {
			_expression->Interpret(c);
		}
	}

private:
	Expression *_expression;
	int _times;
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace InterpreterPattern;
class ut_InterpreterPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_InterpreterPattern, Operation)
{
	//������ģʽ��ʹ��������ʾ�ķ�������˿��Ժ�����ʵ���ķ�����չ��
	//��������ս�����ǿ���ʹ����Ԫģʽ��ʵ���ս���Ĺ���
	Context *c = new Context();
	Expression *tp = new TerminalExpression("echo");
	Expression *ntp = new NonterminalExpression(tp, 4);
	ntp->Interpret(*c);

	delete ntp;
	delete tp;
	delete c;
}
