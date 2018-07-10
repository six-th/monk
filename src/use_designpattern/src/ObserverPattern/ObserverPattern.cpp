/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	�۲���ģʽ
	�۲���ģʽӦ�ÿ���˵��Ӧ����ࡢӰ������ģʽ֮һ��
	��Ϊ �۲��ߵ�һ��ʵ�� Model/View/Control��MVC���ṹ��ϵͳ�����ܹ���������ź���Ҫ�ĵ�λ�����壬MVCʵ����ҵ���߼��ͱ�ʾ��Ľ��
	��Ȼ��MVC ֻ�� �۲���ģʽ��һ��ʵ�����۲���ģʽҪ���������Ϊ��
	����һ��һ��Subject���ԶࣨObserver����������ϵ������������"һ"�仯��ʱ���������"һ"�Ķ�Ҳ�ܹ�ͬ���ı䡣
	
	�����һ�����Ӿ��ǣ�
	��ͬһ�����ݽ���ͳ�Ʒ���ʱ������ϣ���ܹ��ṩ������ʽ�ı�ʾ�������Ա�����ͳ����ʾ����״ͼͳ����ʾ���ٷֱ�ͳ����ʾ�ȣ���
	��Щ��ʾ��������ͬһ�����ݣ����ǵ�Ȼ��Ҫ�����ݸı��ʱ�����е�ͳ�Ƶ���ʾ���ܹ�ͬʱ�ı䡣�۲���ģʽ���ǽ������һ�����⡣ 
	
	Ŀ�� Subject �ṩ���������Ĺ۲��ߵ�ע�ᣨAttach����ע����Detach��������
	�����ṩ��ʹ���������������й۲���ͬ���Ĳ�����Notify����
	�۲������ṩһ�� Update ������ע������� �۲��ߵ� Update ���������� �۲��߸ı��� Subject Ŀ��״̬��ʱ��Ͷ��Լ����и��£�
	������²���Ҫ�ӳٵ� Subject ���󷢳� Notify ֪ͨ���й۲��߽����޸ģ����� Update���� 
	
	�۲���ģʽҲ��Ϊ���������ģ�publish-subscribe����Ŀ�����֪ͨ�ķ����ߣ��۲�������֪ͨ�Ķ����ߣ�����֪ͨ����
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;

namespace ObserverPattern {

class Subject;
////////////////////////////////////////////////////////////////////////////////////////////////////

class Observer 
{
public:
	virtual ~Observer(){}
	virtual void Update(Subject* sub) = 0;
	virtual void PrintInfo() = 0;
	
protected:
	Observer(){}
	string _st;
};

class Subject 
{
public:
	virtual ~Subject(){/*_obvs.clear();*/}
	
	virtual void SetState(const string& st) = 0;
	virtual string GetState() = 0;
	
	virtual void Attach(Observer* obv)
	{
		_obvs.push_front(obv);
	}
	virtual void Detach(Observer* obv)
	{
		if (obv != nullptr) {
			_obvs.remove(obv);
		}
	}
	virtual void Notify()
	{
		for (auto obv : _obvs) {
			obv->Update(this);
		}
	}
	
protected:
	Subject(){}
private:
	list<Observer*> _obvs;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

class ConcreteSubject :public Subject 
{
public:
	string GetState(){return _st;}
	void SetState(const string& st){_st = st;}
private:
	string _st;
};

class ConcreteObserverA :public Observer 
{
public:
	ConcreteObserverA(Subject* sub)
	{
		_sub = sub;
		_sub->Attach(this);
	}

	~ConcreteObserverA()
	{
		_sub->Detach(this);
		//if (_sub != nullptr) {
		//	  delete _sub;
		//}
	}
	virtual Subject* GetSubject()
	{
		return _sub;
	}
	
	void Update(Subject* sub)
	{
		_st = sub->GetState();
		PrintInfo();
	}
	void PrintInfo()
	{
		cout << "ConcreteObserverA::PrintInfo\t" << _sub->GetState() << endl;
	}
	
private:
	Subject *_sub;
};

class ConcreteObserverB :public Observer 
{
public:
	ConcreteObserverB(Subject* sub)
	{
		_sub = sub;
		_sub->Attach(this);
	}

	~ConcreteObserverB()
	{
		_sub->Detach(this);
		//if (_sub != nullptr) {
		//	  delete _sub;
		//}
	}
	virtual Subject* GetSubject()
	{
		return _sub;
	}
	
	void Update(Subject* sub)
	{
		_st = sub->GetState();
		PrintInfo();
	}
	void PrintInfo()
	{
		cout << "ConcreteObserverB::PrintInfo\t" << _sub->GetState() << endl;
	}
	
private:
	Subject *_sub;
};

}//end namespace

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace ObserverPattern;
class ut_ObserverPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F(ut_ObserverPattern, Operation)
{
	Subject *sub = new ConcreteSubject();
	Observer *a1 = new ConcreteObserverA(sub);
	Observer *a2 = new ConcreteObserverA(sub);
	
	Observer *b1 = new ConcreteObserverB(sub);
	Observer *b2 = new ConcreteObserverB(sub);
	
	sub->SetState("old");
	sub->Notify();
	
	sub->SetState("new");
	sub->Notify();

	delete a1;
	delete a2;
	delete b1;
	delete b2;
	
	delete sub;
}
