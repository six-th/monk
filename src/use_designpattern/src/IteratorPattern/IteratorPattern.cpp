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
	������ģʽҲ�������������һ���ۺ϶���ı������⣬���Ծۺϵı�����װ��һ�����н��У������ͱ����˱�¶����ۺ϶�����ڲ���ʾ�Ŀ��ܡ� 
	
	������ 
	������ģʽ��������
	����һ���ۺ϶�������ݶ����豩¶�����ڲ���ʾ��
	֧�ֶԾۺ϶���Ķ��ֱ�����
	Ϊ������ͬ�ľۺϽṹ�ṩһ��ͳһ�Ľӿ� (��, ֧�ֶ�̬����)��
	
	������ģʽ��������Ҫ�����ã� 
	1 ) ��֧���Բ�ͬ�ķ�ʽ����һ���ۺ� ���ӵľۺϿ��ö��ַ�ʽ���б�����
		���� , ������ �ɺ�������Ҫ�����﷨���������������ɿ��԰�������߰�ǰ���������﷨��������
		���� ��ģʽʹ�øı�����㷨��ú����� : 
		������һ����ͬ�ĵ�������ʵ������ԭ�ȵ�ʵ�����ɡ� ��Ҳ�����Լ������������������֧���µı����� 
	2) ���������˾ۺϵĽӿ� ���˵������ı����ӿڣ��ۺϱ���Ͳ�����Ҫ���Ƶı����ӿ��ˡ������ͼ��˾ۺϵĽӿڡ� 
	3) ��ͬһ���ۺ��Ͽ����ж������ÿ���������������Լ��ı���״̬����������ͬʱ���ж��������
	
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
// 
namespace IteratorPattern {
class Iterator;
typedef int Object;

//�ۺ�:�ۺ϶��崴����Ӧ����������Ľӿ�
class Aggregate 
{
public:
	Aggregate(){};
	virtual ~Aggregate(){};
	virtual Iterator* CreateIterator() = 0;
	virtual Object GetItem(int idx) = 0;
	virtual int GetSize() = 0;
};

// ������������ʺͱ���Ԫ�صĽӿڡ� 
class Iterator 
{
public:
	Iterator(){}
	virtual ~Iterator(){}
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;
};

//���������
class ConcreteIterator :public Iterator 
{
public:
	ConcreteIterator(Aggregate *ag, int idx  = 0)
	{
		_ag = ag;
		_idx = idx;
	}

	void First(){_idx = 0;}
	
	void Next()
	{
		if (_idx < _ag->GetSize()) {
			_idx++;
		}
	}
	bool IsDone()
	{
		return (_idx == _ag->GetSize());
	}
	
	Object CurrentItem()
	{
		return _ag->GetItem(_idx);
	}
	
private:
	Aggregate* _ag;
	int _idx;
};

//����ۺ�ʵ�ִ�����Ӧ�������Ľӿڣ��ò�������ConcreteIterator��һ���ʵ���ʵ���� 
class ConcreteAggreaget :public Aggregate 
{
public:
	enum { SIZE = 3 };
	ConcreteAggreaget()
	{
		for (int i = 0; i < SIZE; i++) {
			_objs[i] = i;
		}
	}
	Iterator* CreateIterator()
	{
		return new ConcreteIterator(this);
	}
	
	Object GetItem(int idx)
	{
		if (idx < this->GetSize()) {
			return _objs[idx];
		}
		else {
			return -1;
		}
	}
	
	int GetSize()
	{
		return SIZE;
	}
private:
	Object _objs[SIZE];
};
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
using namespace IteratorPattern;
class ut_IteratorPattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST_F(ut_IteratorPattern, Operation)
{
	Aggregate* ag = new ConcreteAggreaget();
	Iterator *it = ag->CreateIterator();
	
	for (; !(it->IsDone()); it->Next()) {
		cout << it->CurrentItem() << endl;
	}
	delete it;
	delete ag;
}