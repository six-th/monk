/***************************************************************************************************
Author:liu.hao

Time:2018-4

info:

***************************************************************************************************/
#ifndef __ncOldCustomString
#define __ncOldCustomString

#ifdef __WINDOWS__
    #define usleep   Sleep
    //copy����ʱ�����:��λ����
    #define LOSS_TIME  100
#else
    //copy����ʱ�����:��λ΢��
    #define LOSS_TIME  100000
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////

class ncOldCustomString
{
public:
    ncOldCustomString()
        :_str(nullptr)
    {
    }
    
    ncOldCustomString(const char* source)
        :_str(nullptr)
    {
        MK_PRINT_MSG("--(const char* source)");
        
        _str = new char[strlen(source)+1];
        strcpy(_str, source);
        usleep (LOSS_TIME * strlen(source) );//ģ���������ݳ�Ա��memcopy
    }
    
    ncOldCustomString(const ncOldCustomString& source)
    {
        MK_PRINT_MSG("--(const ncOldCustomString& source)");
        
        _str = new char[strlen(source._str) + 1];
        strcpy(_str, source._str);
        usleep (LOSS_TIME * strlen(source._str) );//ģ���������ݳ�Ա��memcopy
    }
    
    ncOldCustomString& operator = (const ncOldCustomString& source)
    {
        MK_PRINT_MSG("--operator = (const ncOldCustomString& source)");
        
        if (this != &source){
            char *tmp = new char[strlen(source._str) + 1];
            strcpy(tmp, source._str);
            usleep (LOSS_TIME * strlen(source._str) );//ģ���������ݳ�Ա��memcopy
            delete []_str;
            _str = tmp;
        }
        return *this;
    }
    
   //��������
    ~ncOldCustomString()
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