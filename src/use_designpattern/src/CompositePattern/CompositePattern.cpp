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
	���ģʽ
	�ڿ����У����Ǿ�������Ҫ�ݹ鹹����״����Ͻṹ�����ģʽ���ṩ�˺ܺõĽ��������
	
	�Աȣ�
	���ģʽͨ����װ��ģʽ�������ƵĽṹͼ��
	�������ģʽּ�ڹ����࣬�� Decorator ģʽ���ڲ��������༴�ɸ��������ְ��
	װ��ģʽ�������Σ������ģʽ���ڱ�ʾ��
***************************************************************************************************/
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;

namespace CompositePattern {

class Component 
{
public:
	virtual ~Component() { }
	
	virtual void Operation() { }
	virtual void Add(const Component& com) { }
	virtual void Remove(const Component& com) { }
	virtual Component* GetChild(int index) {return 0;}
};

class Composite :public Component 
{
public:
	void Add(Component* com) 
	{
		_coms.push_back(com);
	}

	void Operation() 
	{
		for (auto com : _coms)
			com->Operation();
	}

	void Remove(Component* com) 
	{
		//_coms.erase(&com);
	}

	Component* GetChild(int index) 
	{
		return _coms[index];
	}

private:
	std::vector<Component*> _coms;
};

class Leaf :public Component 
{
public:
	void Operation()
	{
		cout << "Leaf::Operation..." << endl;
	}
};

}

////////////////////////////////////////////////////////////////////////////////////////////////////
// ut
//

using namespace CompositePattern;

class ut_CompositePattern : public testing::Test
{
protected:
	static void SetUpTestCase(){}
	static void TearDownTestCase(){}
	virtual void SetUp(){}
	virtual void TearDown(){}
};

TEST(ut_CompositePattern, Operation)
{
	//���ģʽ��ʵ������һ���������Ҫ�ṩ�����ӽڵ㣨Leaf���Ĺ�����ԣ�
	//����ʹ�õ��� STL �е� vector�������ṩ������ʵ�ַ�ʽ�������顢����Hash ��ȡ�
	
	Leaf *leaf = new Leaf();
	leaf->Operation();
	Composite *com = new Composite();
	com->Add(leaf);
	com->Operation();
	Component *leaf_ = com->GetChild(0);
	leaf_->Operation();

	delete leaf;
	delete com;
}