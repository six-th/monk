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
	��������ģʽ Factory Method
	����ģʽ������򵥹���ģʽ��࣬
	���ڼ򵥹���ģʽ�£�ÿ�����һ����Ʒ���඼�����ڹ����������һ���жϷ�֧������Υ���˿���-���ԭ��
	��ˣ�����ģʽ����Ϊ�˽���������������ġ�
	��Ȼÿ�ζ�Ҫ�жϣ����ҾͰ���Щ�ж϶�����һ���������࣬
	������ÿ����Ӳ�Ʒ�����ʱ��ֻ�������һ����������Ϳ����ˡ���������������ѭ�˿���-���ԭ��
	
	ͬ������ģʽһ��Ӧ���ڳ����д󲿷ֵط���ֻʹ������һ�ֲ�Ʒ��������Ҳ����Ƶ��������Ʒ��������
	�����޸ĵ�ʱ��ֻ��Ҫ�޸����޵ļ����ط����ɡ�
	
	�ŵ�
	������򵥹���ģʽһ�£����һ���ŵ������ѭ�˿���-���ԭ��ʹ��ģʽ������Ը�ǿ��
	ȱ��
	��򵥹���ģʽ��ࡣ
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>

namespace FactoryPattern {
////////////////////////////////////////////////////////////////////////////////////////////////////
// ��Ʒ�ӿں͹����ӿ�
//

class AbstractProduct 
{
public:
	virtual ~AbstractProduct() { }
	virtual void Operation() = 0;
};

class AbstractFactory 
{
public:
	virtual AbstractProduct* CreateProduct() = 0;
	virtual ~AbstractFactory() { }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// �����Ʒʵ��
//

class ProductA1 :public AbstractProduct 
{
public:
	ProductA1() {}
	~ProductA1(){}
	
	void Operation() {std::cout << "ProductA1::Operation()" << std::endl;}
};

class ProductA2 :public AbstractProduct 
{
public:
	ProductA2() {}
	~ProductA2(){}
	
	void Operation() {std::cout << "ProductA2::Operation()" << std::endl;}
};


////////////////////////////////////////////////////////////////////////////////////////////////////
// ���幤��ʵ��
//
class ConcreteFactory1 :public AbstractFactory 
{
public:
	ConcreteFactory1() {}
	~ConcreteFactory1() {}
	
	AbstractProduct* CreateProduct() {return new ProductA1();}
};

class ConcreteFactory2 :public AbstractFactory 
{
public:
	ConcreteFactory2() {}
	~ConcreteFactory2() {}
	
	AbstractProduct* CreateProduct() {return new ProductA2();}
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//
class ut_FactoryPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_FactoryPattern, Operation)
{
	{
		FactoryPattern::AbstractFactory *factory = new FactoryPattern::ConcreteFactory1();
		FactoryPattern::AbstractProduct *product = factory->CreateProduct();
		product->Operation();
		delete factory;
		delete product;
	}
	{
		FactoryPattern::AbstractFactory *factory = new FactoryPattern::ConcreteFactory2();
		FactoryPattern::AbstractProduct *product = factory->CreateProduct();
		product->Operation();
		delete factory;
		delete product;
	}
}