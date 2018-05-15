/***************************************************************************************************
Author:liu.hao

Time:2017-12

info:
	����ģʽ
	����ģʽͨ���������װ��һ������Command���У�
	��������Ľ����ߴ�ŵ������ Concrete�������У�Receiver���У�
	�Ӷ�ʵ�ֵ��ò����Ķ���Ͳ����ľ���ʵ����֮��Ľ�� 
	
	����ģʽ�ṹͼ�У�������Ľ����ߣ������ߣ��ŵ�����ľ�������ConcreteCommand�����У�
	��������ʱ��Invoker ���� Invoke ��Ϣ����������󣩣�
	ConcreteCommand����������󽻸� Receiver ������д��� 
	
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

namespace CommandPattern {

class Reciever 
{
public:
	void Action() {cout << "Reciever::Action..." << endl;}
};

class Command 
{
public:
	virtual ~Command() { }
	virtual void Excute() = 0;
};

class ConcreteCommand :public Command 
{
public:
	ConcreteCommand(Reciever *rev) 
	{
		_rev = rev;
	}
	
	void Excute() 
	{
		_rev->Action();
	}
private:
	Reciever *_rev;
};

class Invoker 
{
public:
	Invoker(Command* cmd) 
	{
		_cmd = cmd;
	}
	void Invoke() 
	{
		_cmd->Excute();
	}

private:
	Command *_cmd;
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//

using namespace CommandPattern;

class ut_CommandPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_CommandPattern, Operation)
{
	//ʵ���ϣ�����ģʽ�ؼ������ṩһ������������࣬����ִ�в�����װ�� Command��ӿ��У�
	//��������һ�����ֻ��һЩ�ӿڵļ��ϣ����������κε���������
	Reciever *rev = new Reciever();
	Command* cmd = new ConcreteCommand(rev);
	Invoker *inv = new Invoker(cmd);
	inv->Invoke();

	delete rev;
	delete cmd;
	delete inv;
	/*
	����ģʽ�����ò����Ķ����֪�����ʵ�ָò����Ķ�����
	Invoker ��������Ͳ�֪����������Ǹ������ڴ��� Excute��������ȻҪ֪�����������Ķ���Ҳ���˶��ѣ���
	������Ҫ�����µĴ��������������ף����ǿ���ͨ�������µļ̳��������������ʵ����һ�㡣
	����ģʽ���Ժ� Memento ģʽ���������֧��ȡ���Ĳ�����
	*/
}
