/***************************************************************************************************
Author:liu.hao

Time:2018-4

info:

***************************************************************************************************/

#ifndef __ncLargeStruct
#define __ncLargeStruct

#ifndef __ENABLE_CXX11__
    #define nullptr    NULL
#endif

#ifdef __WINDOWS__
    #define usleep   Sleep
    //copy����ʱ�����:��λ����
    #define LOSS_TIME  10
#else
    //copy����ʱ�����:��λ΢��
    #define LOSS_TIME  10000
#endif

//ģ��һ��copy���ܲ�̫�õ�struct
class ncLargeStruct
{
public:
    ncLargeStruct()
        :_str(nullptr)
    {
        //Ĭ��1k�ֽ�
        _str = new char[1024];
        memset(_str, 'a', 1024);
        usleep (1000);//ģ���������ݳ�Ա�ĳ�ʼ������
    }
    
    ncLargeStruct(const char* source)
        :_str(nullptr)
    {
        _str = new char[strlen(source)+1];
        strcpy(_str, source);
        usleep (LOSS_TIME);//ģ���������ݳ�Ա��copy����
    }
    
    ncLargeStruct(const ncLargeStruct& source)
    {
        _str = new char[strlen(source._str) + 1];
        strcpy(_str, source._str);
        usleep (LOSS_TIME);//ģ���������ݳ�Ա��copy����
    }
    
    ncLargeStruct& operator = (const ncLargeStruct& source)
    {
        if (this != &source){
            char *tmp = new char[strlen(source._str) + 1];
            strcpy(tmp, source._str);
            usleep (LOSS_TIME);//ģ���������ݳ�Ա��copy����
            delete []_str;
            _str = tmp;
        }
        return *this;
    }
    
    #ifdef __ENABLE_CXX11__
    ncLargeStruct(ncLargeStruct&& source)
    {
        _str = source._str;
        source._str = nullptr;
    }
    
    ncLargeStruct& operator = (ncLargeStruct&& source)
    {
        _str = source._str;
        source._str = nullptr;
        return *this;
    }
    #endif
    
   //��������
    ~ncLargeStruct()
    {
        if (_str) {
            delete[] _str;
            _str = nullptr;
        }
    }
private:
    char*       _str;
};

#endif