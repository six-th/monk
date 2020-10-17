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
	���������ϵͳ�Ŀ�������ƹ��̣�����������һ�����������������Requirement Changing����
	�����������õ�һ����ơ�ʵ����һ��ϵͳԭ�ͣ����ǵĿͻ��ֻ������µ�����
	��������˲��ò�ȥ�޸����е���ƣ�
	������ǽ���������Ǹ��Ѿ���ơ�ʵ�ֺõ�������µķ���ȥʵ�ֿͻ��µ�����
	��������������Ʊ�������ʣ���ͣ�ش򲹶���������ĺ��������Ƹ����Ͳ����ܷ�ա�������Զ��������ϵͳ���롣
	������ģʽ���ṩ��һ�ֽ��������
	�����£��������װ��һ�����У����ʲ����������ɴ��������ṩһ�����սӿڣ���ɴﵽЧ���� 
	
	������ģʽ�ڲ��ƻ����ǰ���£�Ϊ���ṩ�����µ��²�����
	�ڷ�����ģʽ�� Accept()������һ��˫���ɵĲ�����
	���������һ������� Accept()�������������������أ�
	1��Element �����ͣ���Ҫ����� Element ���͵�����ſ��Ծ������׵�����һ�� Accept����ʵ�֣�
	2�������ߵ����͡�
	
	Accept()������һ��������Visitor* vis����
	Ҫ������ʵ�ʴ������ķ����ߵ�ʵ�����ſ��Ծ��������ǵ����ĸ� ConcreteVisit()ʵ�֡�
	
	��ɫ����
	��������ߣ�Visitor����ɫ��������һ�����߶�����ʲ������γ����еľ���Ԫ�ؽ�ɫ����ʵ�ֵĽӿڡ�
	��������ߣ�ConcreteVisitor����ɫ��ʵ�ֳ�������߽�ɫ�������Ľӿڣ�Ҳ���ǳ���������������ĸ������ʲ�����
	����ڵ㣨Element����ɫ������һ�����ܲ���������һ�������߶�����Ϊһ��������
	����ڵ㣨ConcreteElement����ɫ��ʵ���˳���Ԫ�����涨�Ľ��ܲ�����
	�ṹ����ObiectStructure����ɫ�������µ�һЩ���Σ����Ա����ṹ�е�����Ԫ�أ�
		�����Ҫ���ṩһ���߲�εĽӿ��÷����߶�����Է���ÿһ��Ԫ�أ�
		�����Ҫ��������Ƴ�һ�����϶������һ���ۼ������У�List���򼯺ϣ�Set���� 
	
	�ص�:
	����ģʽ�����ݽṹ�������ڽṹ�ϵĲ�������ϣ�ʹ�ò������Ͽ�������ɵ��ݻ�
	������ģʽ���������ݽṹ����ȶ��㷨���ױ仯��ϵͳ����Ϊ������ģʽʹ���㷨�������ӱ�����ס�
	��ϵͳ���ݽṹ�������ڱ仯���������µ����ݶ������ӽ��������ʺ�ʹ�÷�����ģʽ��
	������ģʽ���ŵ������Ӳ��������ף���Ϊ���Ӳ�����ζ�������µķ����ߡ�
	������ģʽ���й���Ϊ���е�һ�������߶����У���ı䲻Ӱ��ϵͳ���ݽṹ����ȱ����������µ����ݽṹ�����ѡ�
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <list>
using namespace std;

namespace VisitorPattern {
	

////////////////////////////////////////////////////////////////////////////////////////////////////

class Visitor;
//Ԫ�ؽӿ�
class Element 
{
public:
	Element(){}
	virtual ~Element(){}
	virtual void Accept(Visitor* vis) = 0;
};

class ConcreteElementA;
class ConcreteElementB;
//�����߽ӿ�
class Visitor 
{
public:
	virtual ~Visitor(){}
	virtual void VisitConcreteElementA(ConcreteElementA* elm) = 0;
	virtual void VisitConcreteElementB(ConcreteElementB* elm) = 0;
protected:
	Visitor(){}
};

//����Ԫ��A
class ConcreteElementA :public Element 
{
public:
	void Accept(Visitor* vis)
	{
		cout << __FUNCTION__ << endl;
		vis->VisitConcreteElementA(this);
	}
	
	void OperationA(){cout << __FUNCTION__ << endl;}
};

//����Ԫ��B
class ConcreteElementB :public Element 
{
public:
	void Accept(Visitor* vis)
	{
		cout << __FUNCTION__ << endl;
		vis->VisitConcreteElementB(this);
	}
	void OperationB(){cout << __FUNCTION__ << endl;}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

//���������
class ConcreteVisitor1 :public Visitor 
{
public:
	void VisitConcreteElementA(ConcreteElementA* elm)
	{
		cout << __FUNCTION__ << endl;
		elm->OperationA();
	}
	
	void VisitConcreteElementB(ConcreteElementB* elm)
	{
		cout << __FUNCTION__ << endl;
		elm->OperationB();
	}
};

//���������
class ConcreteVisitor2 :public Visitor 
{
public:
	void VisitConcreteElementA(ConcreteElementA* elm)
	{
		cout << __FUNCTION__ << endl;
		elm->OperationA();
	}
	
	void VisitConcreteElementB(ConcreteElementB* elm)
	{
		cout << __FUNCTION__ << endl;
		elm->OperationB();
	}
};

// "ObjectStructure"
class ObiectStructure
{
public: 
	void Attach( Element *elem ){vElem.push_back(elem);}
	void Detach( Element *elem ){vElem.remove(elem);}
	void Accept( Visitor *visitor)
	{
		for (std::list<Element*>::iterator iter=vElem.begin(); iter != vElem.end(); ++iter){
			(*iter)->Accept(visitor);
		}
	}
private:
	list< Element*> vElem;
};

}//end namespace


////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace VisitorPattern;
class ut_VisitorPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F(ut_VisitorPattern, Operation)
{
	/*liu.hao
	������ģʽ��ȱ��:
	������ģʽʹ�����������µĲ�������������һ���µķ����߼�����һ������ṹ�϶���һ���µĲ�����������ӷ�����3
	�����µ�ConcreteElement������ѣ���Ҫ��ӣ������Visitor�ӿ���Ҫ����½ӿڣ���������������Ҳ������Ӷ�Ӧʵ�֣�
	������Ӧ�÷�����ģʽʱ���ǹؼ���������ϵͳ���ĸ����ֻᾭ���仯��
	�������ڶ��� �ṹ�ϵ��㷨�ػ��ǹ��ɸýṹ�ĸ���������ࡣ
	����������µ�ConcreteElement�������� �Ļ���Vistor���ν��������ά��������˵��������²��ʺ��÷�����ģʽ��
	*/
	
	//��������ṹ
	ObiectStructure* elems = new ObiectStructure();
	elems->Attach(new ConcreteElementA());
	elems->Attach(new ConcreteElementB());
	
	//������1
	Visitor *vis1 = new ConcreteVisitor1();
	elems->Accept(vis1);
	cout<<""<<endl;
	
	//������2
	Visitor *vis2 = new ConcreteVisitor2();
	elems->Accept(vis2);
	
	//todo:
	//delete xx
}
