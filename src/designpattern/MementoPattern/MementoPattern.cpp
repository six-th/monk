/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	����¼ģʽ
	����¼ģʽ�Ĺؼ�����Ҫ�ڲ��ƻ���װ�е�ǰ���£����񲢱���һ������ڲ�״̬�������Ϳ������øñ����״̬ʵʩ�ָ�������
	
	������ģʽ�У�����¼ģʽ����������ά�����Գ�����Undo��������״̬��
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <string>
using namespace std;

namespace MementoPattern {

//����¼
class Memento 
{
	//���ǽ� Originator ��״̬�����ڱ���¼���У���������¼�ӿ� private ������Ҳ�ʹﵽ�˷�װ�Ĺ�Ч��
private:
	//������ؼ��ĵط����� Originator Ϊ friend �࣬���Է����ڲ���Ϣ�����������಻�ܷ���
	friend class Originator;
	Memento(const string& st) {_st = st;}
	void SetState(const string& st) {_st = st;}
	string GetState() {return _st;}
private:
	string _st;
};

//ԭ����
class Originator 
{
public:
	Originator() {_mt = nullptr;}
	Originator(const string &st) {_st = st;_mt = nullptr;}

	Memento* CreateMemento() {return new Memento(_st);}
	void SetMemento(Memento* mt) {_mt = mt;}
	void RestoreToMemento(Memento* mt) {_st = mt->GetState();}
	
	string GetState() {return _st;}
	void SetState(const string& st) {_st = st;}
	void PrintState() {cout << _st << "..." << endl;}

private:
	string _st;
	Memento *_mt;
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace MementoPattern;
class ut_MementoPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F(ut_MementoPattern, Operation)
{
	Originator *o = new Originator();
	o->SetState("old");
	o->PrintState();
	Memento *m = o->CreateMemento();
	o->SetState("new");
	o->PrintState();
	o->RestoreToMemento(m);
	o->PrintState();

	delete o;
	delete m;
}
