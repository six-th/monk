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
