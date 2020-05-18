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
	ģ�巽��ģʽ
	����ĳһ��ҵ���߼����㷨ʵ�֣��ڲ�ͬ�Ķ������в�ͬ��ϸ��ʵ�֣�
	�����߼����㷨���Ŀ�ܣ���ͨ�õ�Ӧ���㷨������ͬ�ġ�ģ�巽���ṩ�����������һ��ʵ�ֿ�ܡ�
	ģ�巽��ģʽ�ǲ��ü̳еķ�ʽʵ����һ�㣺���߼����㷨����ܷ��ڳ�������У��������ϸ�ڵĽӿڣ�������ʵ��ϸ�ڡ�
	
	ģ�巽��ģʽ���һ�ַ�����ƽṹЧ����
	��Ҳ���������ϵͳ�ķ����������һ��ԭ�� DIP���������ã�Dependency Inversion Principles����
	�京����Ǹ����������Ĳ������߲�ģ����õͲ�ģ��Ĳ��������Ͳ�ģ��ʵ�ָ߲�ģ�������Ľӿڡ�
	��������Ȩ�ڸ��ࣨ�߲�ģ�飩���Ͳ�ģ�鷴��Ҫ�����߲�ģ�顣
	
	�Աȣ�
	Strategy ģʽ������Ǻ�ģ�巽��ģʽ���Ƶ����⣬
	���� Strategy ģʽ�ǽ��߼����㷨����װ��һ�����У�����ȡ��ϣ�ί�У��ķ�ʽ���������⡣ 
	
	ȱ�㣺
	�̳е�ǿ����Լ����ϵҲ��ģ�巽��ģʽ�в���ĵط���
	���ǿ��Կ������� ConcreteClass ���е�ʵ�ֵ�ԭ�﷽�� PrimitiveOperation1()���ǲ��ܱ�����ิ�á�
	��������Ҫ����һ�� AbstractClass �ı��� AnotherAbstractClass����������ֻ��ͨ���㷨��һ����
	��ԭ������븴�� AbstractClass �������ʵ�֡��������ǲ�����ʵ�ֵģ�
	��Ϊ ConcreteClass �̳���AbstractClass��Ҳ�ͼ̳��� AbstractClass ��ͨ���㷨��
	AnotherAbstractClass �Ǹ��ò���ConcreteClass ��ʵ�֣���Ϊ���߲��Ǽ̳���ǰ�ߡ�
	ģ�巽��ģʽ��¶������Ҳ���Ǽ̳������е����⣬
	����ģʽ��ͨ����ϣ�ί�У����ﵽ��ģ�巽��ģʽ���Ƶ�Ч��������۾��ǿռ��ʱ���ϵĴ��ۣ�
	���ڲ���ģʽ����ϸ������ο� Strategy ģʽ������
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace TemplatePattern {
class AbstractClass 
{
public:
	virtual void TemplateMethod() 
	{
		PrimitiveOperation1();
		PrimitiveOperation2();
	}
	virtual ~AbstractClass() { }
protected:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
	AbstractClass() { }
};

class ConcreteClass1 :public AbstractClass 
{
public:
	void PrimitiveOperation1() {cout << "ConcreteClass1::PrimitiveOperation1" << endl;}
	void PrimitiveOperation2() {cout << "ConcreteClass1::PrimitiveOperation2" << endl;}
};

class ConcreteClass2 :public AbstractClass {
public:
	void PrimitiveOperation1() {cout << "ConcreteClass2::PrimitiveOperation1" << endl;}
	void PrimitiveOperation2() {cout << "ConcreteClass2::PrimitiveOperation2" << endl;}
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace TemplatePattern;
class ut_TemplatePattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F(ut_TemplatePattern, Operation)
{
	AbstractClass *p1 = new ConcreteClass1();
	p1->TemplateMethod();
	delete p1;
	
	AbstractClass *p2 = new ConcreteClass2();
	p2->TemplateMethod();
	delete p2;
}