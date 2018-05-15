/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	������ģʽ��������ģʽ��
	��ͼ��
	��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
	����ʾ�������п���ͨ�����벻ͬ�Ĳ���ʵ����һ�㣩��
	
	�����ԣ�
	��ͬʱ�������������ʱ�����ʹ��Builderģʽ
	a. ���������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ�䷽ʽ��
	b. ��������̱���������Ķ����в�ͬ�ı�ʾ��
	
	�Աȣ�
	������ģʽ�ͳ��󹤳�ģʽ�ڹ����Ϻ����ƣ���Ϊ��������������ĸ��ӵĶ���
	���ǵ������ǣ�������ģʽǿ������һ�����������󣬲�ͨ����ͬ�Ĵ������̿��Ի�ò�ͬ�Ľ������
	һ����˵������ģʽ�ж�����ֱ�ӷ��صġ�
	���� AbstractFactory ģʽ�ж�����ֱ�ӷ��صģ�
	���󹤳�ģʽǿ������Ϊ��������໥�����Ķ����ṩһ��ͬһ�Ľӿڡ�
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace BuilderPattern {
// Product
class Product 
{
public:
	Product() {cout << "Product..." << endl;}
	
	void setPartA(const string& s){cout <<s<< endl; m_partA = s;}
	void setPartB(const string& s){cout <<s<< endl; m_partB = s;}
	void setPartC(const string& s){cout <<s<< endl; m_partC = s;}
private:
	string m_partA;
	string m_partB;
	string m_partC;
};

// Builder:����һ������ӿڣ��Թ淶��Ʒ����ĸ�����ɳɷֵĽ��졣
class Builder 
{
public:
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
	virtual Product* GetProduct() = 0;
	virtual ~Builder() { }
};

//���彨����:���������ɫ������Ӧ�ó��������ص��࣬������Ӧ�ó�������´�����Ʒʵ����
class ConcreteBuilder1 :public Builder 
{
public:
	ConcreteBuilder1() {m_pProduct = new Product();}
	~ConcreteBuilder1(){delete m_pProduct;}
	
	void BuildPartA() {m_pProduct->setPartA("A"); cout << "BuildPartA..." << endl;}
	void BuildPartB() {m_pProduct->setPartA("B"); cout << "BuildPartB..." << endl;}
	void BuildPartC() {m_pProduct->setPartA("C"); cout << "BuildPartC..." << endl;}

	Product* GetProduct() 
	{
		return m_pProduct;
	}
	
private:
	Product* m_pProduct;
};

class ConcreteBuilder2 :public Builder 
{
public:
	ConcreteBuilder2() {m_pProduct = new Product();}
	~ConcreteBuilder2(){delete m_pProduct;}
	
	void BuildPartA() {m_pProduct->setPartA("aa"); cout << "BuildPartA..." << endl;}
	void BuildPartB() {m_pProduct->setPartA("bb"); cout << "BuildPartB..." << endl;}
	void BuildPartC() {m_pProduct->setPartA("cc"); cout << "BuildPartC..." << endl;}

	Product* GetProduct() 
	{
		return m_pProduct;
	}
	
private:
	Product* m_pProduct;
};

// ָ����:���������ɫ������þ��彨���߽�ɫ�Դ�����Ʒ����
class Director 
{
public:
	Director(Builder* pBuilder) {_builer = pBuilder;}

	void Construct() 
	{
		_builer->BuildPartA();
		_builer->BuildPartB();
		_builer->BuildPartC();
	}

private:
	Builder *_builer;
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//

using namespace BuilderPattern;

class ut_BuilderPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_BuilderPattern, Operation)
{
	{
		auto builder = new ConcreteBuilder1();
		auto director = new Director(builder);
		director->Construct();
		Product* product = builder->GetProduct();
		
		delete builder;
		delete director;
	}
	
	{
		auto builder = new ConcreteBuilder2();
		auto director = new Director(builder);
		director->Construct();
		Product* product = builder->GetProduct();
		
		delete builder;
		delete director;
	}
}