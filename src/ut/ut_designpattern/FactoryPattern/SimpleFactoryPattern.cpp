/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	�򵥹���ģʽ
	
	�򵥹���ģʽһ��Ӧ���ڳ����д󲿷ֵط���ֻʹ������һ�ֲ�Ʒ��������Ҳ����Ƶ��������Ʒ��������
	�����޸ĵ�ʱ��ֻ��Ҫ�޸����޵ļ����ط����ɡ�
	
	�ͻ�ֻ��Ҫ֪��SimpleFactory�Ϳ����ˣ�ʹ�õ�ʱ��Ҳ��ʹ�õ�AbstractFactory��
	�����ͻ���ֻ�ڵ�һ�δ���������ʱ����֪�������ϸ�ڵģ�����ʱ������ֻ֪��AbstractFactory��
	�����������Ĵﵽ��������ת��ԭ��
	
	�ŵ�
	1.�����˶��󴴽���ϸ�ڣ�����Ʒ��ʵ�����Ƴٵ�������ʵ�֡�
	2.�ͻ��˻������ù���ʹ�õ����ĸ���Ʒ��ֻ��Ҫ֪�����ĸ����������ˣ��ṩ������Ҳ�����ñȽϱ���ʶ����ַ�����
	3.��������µĲ�Ʒ���࣬ÿ��ֻ��Ҫ�޸Ĺ����ഫ�ݵ�����ֵ�����ˡ�
	4.��ѭ��������תԭ��
	ȱ��
	1.Ҫ���Ʒ��������Ͳ�࣬ʹ�õķ���������ͬ�������Ƚ϶࣬�����е����ֱ���Ҫ���һ�ַ���������Ƿǳ��鷳�����顣
		������һ������һ�����м��ַ�������ͬ���ͻ����޷�֪������һ����Ʒ���࣬Ҳ���޷������⼸������ͬ�ķ�����
	2.ÿ���һ����Ʒ���࣬�������ڹ����������һ���жϷ�֧����Υ���˿���-���ԭ��
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>

namespace SimpleFactoryPattern {
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
	virtual AbstractProduct* CreateProduct(int type) = 0;
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
// �򵥹���ʵ��
//
class SimpleFactory :public AbstractFactory 
{
public:
	SimpleFactory() {}
	~SimpleFactory() {}
	
	AbstractProduct* CreateProduct(int type) 
	{
		AbstractProduct* result = nullptr;
		
		switch(type) {
		case 1:
			result = new ProductA1();
			break;
		case 2:
			result = new ProductA2();
			break;
		case 3:
			//result = new ProductA3();
			break;
		default:
			break;
		}
		
		return result;
	}
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//
class ut_SimpleFactoryPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_SimpleFactoryPattern, Operation)
{
	SimpleFactoryPattern::AbstractFactory *factory = new SimpleFactoryPattern::SimpleFactory();
	
	{
		SimpleFactoryPattern::AbstractProduct *product = factory->CreateProduct(1);
		product->Operation();
		delete product;
	}
	
	{
		SimpleFactoryPattern::AbstractProduct *product = factory->CreateProduct(2);
		product->Operation();
		delete product;
	}
	
	delete factory;
}