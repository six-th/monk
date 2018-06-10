# ut_std
using google test;

## ���� 0-Language
* �������� 0-BasicConcepts
* C++ �ؼ��� 1-Keywords
* Ԥ������ 2-Preprocessor
* ���ʽ 3-Expressions
* ���� 4-Declaration
* ��ʼ�� 5-Initialization
* ���� 6-Functions
* ��� 7-Statements
* �� 8-Classes
* ģ�� 9-Templates
* �쳣 10-Exceptions
* ���� 11-Miscellaneous



## ͷ�ļ� 1-Headers




## ����� 2-Library concepts




## ����֧�ֿ� 3-Language support library
* ����֧�� Type support
* �������� traits (C++11)
* ���򹤾� Program utilities
* ��ϵ����� Relational comparators (C++20)
* numeric_limits
* type_info
* initializer_list (C++11)




## ��Ͽ� 4-Diagnostics library




## ͨ�ù��߿� 5-General utilities library
* ����ָ��������� Smart pointers and allocators
* ���ں�ʱ�� Date and time
* �������� Function objects
* hash (C++11)
* �ַ���ת�� String conversions (C++17)
* ���ߺ��� Utility functions
* pair
* tuple (C++11)
* optional (C++17)
* any (C++17)
* variant (C++17) 




## �ַ����� 6-Strings library
* basic_string
* basic_string_view (C++17)
* ����ֹ�ַ��� Null-terminated strings
	* �ֽ� byte
	* ���ֽ� multibyte
	* �� wide




## ������ 7-Containers library
* ˳������ Sequence containers
* �������� Associative containers
* ����������� Unordered associative containers
* ���������� Container adaptors




## �������� 8-Iterators library




## �㷨�� 9-Algorithms library




## ��ֵ�� 10-Numerics library
* ������ѧ���� Common math functions
* ������ѧ���� Special math functions (C++17)
* ��ֵ�㷨 Numeric algorithms
* α��������� Pseudo-random number generation
* ���㻷�� Floating-point environment (C++11)
* complex
* valarray 




## ����/����� 11-Input output library
* ��������I/O Stream-based I/O
* ͬ������� Synchronized output(C++20)
* I/O ���ݷ� I/O manipulators




## ���ػ��� 12-Localizations library




## ������ʽ�� 13-Regular expressions library (C++11)




## ԭ�Ӳ����� 14-Atomic operations library (C++11)




## �߳�֧�ֿ� 15-Thread support library (C++11)




## �ļ�ϵͳ�� 16-Filesystem library (C++17)





# C++����

```C++
## ����
DefaultConstructible    ָ�������Ͷ������Ĭ�Ϲ���
MoveConstructible       ָ�������Ͷ�����Դ���ֵ����
CopyConstructible       ָ�������Ͷ�����Դ���ֵ����
MoveAssignable          ָ�������Ͷ�����Դ���ֵ��ֵ
CopyAssignable          ָ�������Ͷ�����Դ���ֵ��ֵ
Destructible            ָ���ö����������


## ����
TriviallyCopyable       ӵ��ƽ�����ơ���ֵ������������
TrivialType             ӵ��ƽ������������ֵ������������
StandardLayoutType      ������������׼���� (StandartLayout) ��Ա�ķ����࣬������ͬ�ķ��ʿ���
PODType                 POD��������ݣ��ṹ�壬�� C struct ����


## ������ 
�ɱȽ����              operator== �ǵȼ۹�ϵ
�ɱȽ�С��              operator< ���ϸ������ϵ
�ɽ���                  ���÷��޶��ǳ�Ա�������� swap() ����������
��ֵ����                �����õ��ɽ��� (Swappable) ���͵ĵ����� (Iterator)
�ɿ�ָ��                ֧�ֿ��õ���ָ������
��ϣ                    ����ֵ���죬��ͬ������ʵ͵ĺ������� (FunctionObject)
������                  ����������Ϣ��������
��������                ���Ժ��������﷨���õĶ���
�ɵ���                  �����˵��ò���������
Predicate               �е��������Ҳ��޸���������ֵ��ת��Ϊ bool �ĺ������� (FunctionObject)
BinaryPredicate         ��˫�������Ҳ��޸���������ֵ��ת��Ϊ bool �ĺ������� (FunctionObject)
Compare                 ����˳���ϵ�Ķ�Ԫν�� (BinaryPredicate)


## ����  
����                    ����ͨ������������Ԫ�ص����ݽṹ
��������                ʹ��˫�������������
�߷���������            ʹ�÷�����������
˳������                Ԫ�����Դ洢������
�������                Ԫ�ش洢�������ڴ��ַ������
��������                ͨ����Ԫ�ع������ؼ��洢���ǵ�����
�����������            ͨ����Ԫ�ع������ؼ��Խ����Ǵ洢��Ͱ�е�����


## ����Ԫ��  
��Ĭ�ϲ���              ����δ��ʼ���洢Ĭ�Ϲ����Ԫ��
�ɸ��Ʋ���              ����δ��ʼ���洢�и��ƹ����Ԫ��
���ƶ�����              ����δ��ʼ���洢���ƶ�����ĺ���
��ԭλ����              ����δ��ʼ���洢�й����Ԫ��
�ɲ���                  ���÷��������ٵ�Ԫ��


## ������ 
������                  ��һЩ���ݽṹ�ڷ������ݵ�ͨ�ø���
���������              �����ڶ����ݵĵ�����
���������              ������д���ݵĵ�����
��ǰ������              �����ڶ�ζ����ݵĵ�����
˫�������              �������ĵ�����
������ʵ�����          ���ڳ���ʱ�������ӵĵ�����
��ӵ�����              ָ����̷���Ԫ�صĵ�����


## �� I/O ���� 
�޸�ʽ���뺯��          ������ǰ���ո񲢶Դ����ַ������������뺯��
�и�ʽ���뺯��          ����ǰ���ո�������뺯��
�޸�ʽ�������          �������������
�и�ʽ�������          ����ʧ��λ�����������õ����������


## ���������   
��������                Ͷ��һ���������У�����һ�� 32 λ�޷���ֵ������
�������λ������        ���ؾ��ȷֲ�������޷�������
���������              �����Ӷ����ȷ���Ծ������λ������ (UniformRandomBitGenerator)
���������������        ת����һ����������� (RandomNumberEngine) �������������� (RandomNumberEngine)
������ֲ�              ���ط��Ӹ�����ѧ�����ܶȷֲ������������


## ����  
��������                Ϊִ�д������̣߳��ṩ��ռ����Ȩ����
����                    ֧����������ȡ�Ļ������� (BasicLockable)
��ʱ����                ֧�ֶ�ʱ����ȡ�Ŀ��� (Lockable)
����                    ���������������ݾ�����˳��һ��ͬ��Ӱ��Ŀ��� (Lockable)
��ʱ����                ���������������ݾ�����˳��һ��ͬ��Ӱ��Ŀɶ�ʱ�� (TimedLockable)
������                ֧�ֹ�������Ȩ����Ļ��� (Mutex)
����ʱ����            ֧�ֹ�������Ȩ����Ķ�ʱ���� (TimedMutex)


## ����  
һԪ��������            �������͵�����
��Ԫ��������            �����������ͼ�Ĺ�ϵ
�任����                �޸���������
ʱ��                    ��ʱ�ڡ�ʱ��㣬�Լ�ȡ�õ�ǰʱ���ĺ����ۺ�
ƽ��ʱ��                �����쳣��ʱ�� (Clock)
�ַ�����                Ϊ�ַ����Ͷ������ͺͺ���
λ��������              λ����������ö��
��ֵ����                ��ʼ��Ч���ϵ��ڸ�ֵ������
������ʽ����          ��������ʽ�ⶨ�����ͺͺ���
��������                ӵ�� constexpr ���캯��������
```
