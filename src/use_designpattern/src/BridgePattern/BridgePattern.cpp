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
	�Ž�ģʽ
	���ǽ�Abstraction��AbstractionImp֮��Ĺ�ϵ��֮Ϊ�Žӣ���Ϊ���ڳ�����������ʵ��֮�������������ã�ʹ���ǿ��Զ����ر仯��
	4. ������ ����һЩ���ʹ��Bridgeģʽ: 
		�㲻ϣ���ڳ��������ʵ�ֲ���֮����һ���̶��İ󶨹�ϵ���������������������Ϊ���ڳ�������ʱ��ʵ�ֲ���Ӧ���Ա�ѡ������л��� 
		��ĳ����Լ�����ʵ�ֶ�Ӧ�ÿ���ͨ����������ķ����������䡣��ʱBridgeģʽʹ����ԶԲ�ͬ�ĳ���ӿں�ʵ�ֲ��ֽ�����ϣ����ֱ�����ǽ������䡣 
		��һ�������ʵ�ֲ��ֵ��޸�Ӧ�Կͻ�������Ӱ�죬���ͻ��Ĵ��벻�����±��롣
		��C + +������Կͻ���ȫ���س����ʵ�ֲ��֡���C++�У���ı�ʾ����ӿ����ǿɼ��ġ�
		��������ͼһ�ڵĵ�һ����ͼ����ʾ���������������Ҫ���ɡ�����һ�����νṹ˵������뽫һ������ֽ���������֡� R u m b a u g h���������νṹΪ��Ƕ�׵��ջ��� ��nested generalizations����
		�����ڶ������乲��ʵ�֣�����ʹ�����ü���������ͬʱҪ��ͻ�����֪����һ�㡣 һ���򵥵����ӱ���Coplien��String��[Cop92]����������ж��������Թ���ͬһ���ַ�����ʾ��StringRep��
		
	B r i d g eģʽ������һЩ�ŵ㣺
	1) ����ӿڼ���ʵ�ֲ��� һ��ʵ��δ�ز���ذ���һ���ӿ��ϡ��������ʵ�ֿ��� ������ʱ�̽������ã�һ��������������������ʱ�̸ı�����ʵ�֡� 
		��Abstraction��AbstractionImp���������ڽ��Ͷ�ʵ�ֲ��ֱ���ʱ�̵������ԣ����ı�һ�� ʵ����ʱ��������Ҫ���±���Abstraction������Ŀͻ�����
		Ϊ�˱�֤һ�����Ĳ�ͬ�汾֮��Ķ����Ƽ����ԣ�һ��Ҫ��������ʡ� 
		���⣬�ӿ���ʵ�ַ��������ڷֲ㣬�Ӷ��������õĽṹ��ϵͳ��ϵͳ�ĸ߲㲿�ֽ��� ֪��Abstraction��AbstractionImp���ɡ� 
	2) ��߿������� ����Զ����ض�Abstraction��AbstractionImp��νṹ�������䡣 
	3 ) ʵ��ϸ�ڶԿͻ�͸�� ����ԶԿͻ�����ʵ��ϸ�ڣ����繲��AbstractionImp�����Լ���Ӧ�����ü������ƣ�����еĻ���
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace BridgePattern {

//  ���������Ľӿ�
class Abstraction 
{
public:
	virtual void Operation() = 0;
	virtual ~Abstraction() { }
protected:
	Abstraction() { }
};

// ����ʵ����Ľӿڣ��ýӿڲ�һ��Ҫ��Abstraction�Ľӿ���ȫһ�£�
//��ʵ�������� �ӿڿ�����ȫ��ͬ��
//һ�������� AbstractionImp�ӿڽ��ṩ������������ Abstraction�����˻�����Щ���������Ľϸ߲�εĲ�����
class AbstractionImp
{
public:
	virtual void Imp_Operation() = 0;
	virtual ~AbstractionImp() { }
protected:
	AbstractionImp() { }
};

//ʵ��AbstractionImp�ӿڲ��������ľ���ʵ��
class ConcreteAbstractionImpA :public AbstractionImp 
{
public:
	void Imp_Operation() {cout << "ConcreteAbstractionImpA Imp_Operation..." << endl;}
};

//ʵ��AbstractionImp�ӿڲ��������ľ���ʵ��
class ConcreteAbstractionImpB :public AbstractionImp 
{
public:
	void Imp_Operation() {cout << "ConcreteAbstractionImpB Imp_Operation..." << endl;}
};

//������Abstraction����Ľӿ�
class RefinedAbstractionA :public Abstraction 
{
public:
	RefinedAbstractionA(AbstractionImp *imp){_imp = imp;}
	void Operation() 
	{
		cout << "RefinedAbstractionA::Operation()" << endl;
		_imp->Imp_Operation();
	}
	
private:
	AbstractionImp *_imp;
};

//������Abstraction����Ľӿ�
class RefinedAbstractionB :public Abstraction 
{
public:
	RefinedAbstractionB(AbstractionImp *imp){_imp = imp;}
	void Operation() 
	{
		cout << "RefinedAbstractionB::Operation()" << endl;
		_imp->Imp_Operation();
	}
	
private:
	AbstractionImp *_imp;
};

}//namespace end

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//
using namespace BridgePattern;

class ut_BridgePattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_BridgePattern, Operation)
{
	/*
	liu.hao:
	�ٸ�����:
	��һ���ļ�����Ŀ¼���в�����
	ConcreteAbstractionImp���Է�Ϊwindow��linux����������ʵ�֣�
	RefinedAbstraction���Է�Ϊ�������Ķ�����file����dir
	*/
	
	
	//����windows��file�Ĳ���
	{
		AbstractionImp *windows_Imp = new ConcreteAbstractionImpA();
		Abstraction *file = new RefinedAbstractionA(windows_Imp);
		file->Operation();
		delete windows_Imp;
		delete file;
	}
	
	//����linux��file�Ĳ���
	{
		AbstractionImp *linux_Imp = new ConcreteAbstractionImpB();
		Abstraction *file = new RefinedAbstractionA(linux_Imp);
		file->Operation();
		delete linux_Imp;
		delete file;
	}
	
	//����windows��dir�Ĳ���
	{
		AbstractionImp *windows_Imp = new ConcreteAbstractionImpA();
		Abstraction *dir = new RefinedAbstractionB(windows_Imp);
		dir->Operation();
		delete windows_Imp;
		delete dir;
	}
	
	//����linux��dir�Ĳ���
	{
		AbstractionImp *linux_Imp = new ConcreteAbstractionImpB();
		Abstraction *dir = new RefinedAbstractionB(linux_Imp);
		dir->Operation();
		delete linux_Imp;
		delete dir;
	}
}
