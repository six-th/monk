/***************************************************************************************************
LICENSE:
    Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
Author:liu.hao(33852613@163.com)

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
