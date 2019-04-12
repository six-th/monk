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
	����ģʽ
	����һϵ�е��㷨,������һ������װ����, ����ʹ���ǿ��໥�滻����ģʽʹ���㷨�ɶ� ����ʹ�����Ŀͻ����仯�� 
	
	������
	�����ص����������Ϊ���졣�����ԡ��ṩ��һ���ö����Ϊ�е�һ����Ϊ������һ ����ķ����� 
	�㷨ʹ�ÿͻ���Ӧ��֪�������ݡ���ʹ�ò���ģʽ�Ա��Ⱪ¶���ӵġ����㷨��ص��� �ݽṹ�� 
	һ���ඨ���˶�����Ϊ , ������Щ��Ϊ�������Ĳ������Զ������������ʽ���֡� 
		����ص�������֧�������Ǹ��Ե�Strategy�����Դ�����Щ������䡣 
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace StrategyPattern {
class Strategy 
{
public:
	virtual void Interface() = 0;
	virtual ~Strategy() { }
};

class ConcreteStrategyA :public Strategy 
{
public:
	void Interface() {cout << "ConcreteStrategyA::Interface..." << endl;}
};

class ConcreteStrategyB :public Strategy 
{
public:
	void Interface() {cout << "ConcreteStrategyB::Interface..." << endl;}
};

class Context 
{
public:
	Context(Strategy *stg) 
	{
		_stg = stg;
	}

	void DoAction()
	{
		_stg->Interface();
	}
private:
	Strategy *_stg;
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace StrategyPattern;
class ut_StrategyPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F(ut_StrategyPattern, Operation)
{
	Strategy *ps = new ConcreteStrategyA();
	Context *pc = new Context(ps);
	pc->DoAction();

	delete pc;
	delete ps;
}
