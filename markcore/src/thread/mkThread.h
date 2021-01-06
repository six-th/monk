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

Time:2020-6

info:
    �̹߳���
***************************************************************************************************/

#ifndef __mkThread
#define __mkThread

#include<thread>
#include <mutex>
#include <condition_variable>
////////////////////////////////////////////////////////////////////////////////////////////////////
//

class mkThread
{
public:
    mkThread()
        : _threadAbortFlag(false)
    {
        MODULE_TRACE (_T("this = 0x%p"), this);
    }
    
    virtual ~mkThread()
    {
        MODULE_TRACE (_T("this = 0x%p"), this);
    }
    
    virtual void Start(const int count)
    {
        auto threadFunc = [&](std::shared_ptr<Event> threadEvent){
            OnBegin();
            
            while(true) {
                if(_threadAbortFlag){
                    MODULE_TRACE_WITH_LOG (_T("[this = 0x%p]"), this);
                    break;
                }
                
                try {
                    //�����ڶ��߳���ռʽ����ͬһ����Դ����
                    OnProc();
                }
                catch(Exception& e) {
                    OnError(e);
                    MODULE_TRACE_WITH_LOG(_T("error = %s"), e.toFullString().getCStr());
                }
                catch(...) {
                    ncModuleException e(__FILE__, __LINE__, String(_T("unknown error")), Exception::NO_MAPPED_ERROR_ID, g_moduleProvider);
                    OnError(e);
                    MODULE_TRACE_WITH_LOG(_T("error = %s"), e.toFullString().getCStr());
                }
            }
            
            OnEnd();
            
            MODULE_TRACE_WITH_LOG (_T("this = 0x%p, threadId = %d"), this, Thread::getCurThreadId());
            threadEvent->signal();
        };
        
        //Ԥ����n���߳�
        for(int i = 0 ; i != count; ++i) {
            std::shared_ptr<Event> threadEvent = std::make_shared<Event>(false);//false:����signal֮���һ�����wait
            std::shared_ptr<std::thread> threadProc(new std::thread(threadFunc, threadEvent));
            threadProc->detach();
            _vThreadEvents.push_back(threadEvent);
        }
    }
    
    virtual void Stop()
    {
        //ֹͣ�����߳�
        _threadAbortFlag = true;
        OnStop();
        for(auto& threadEvent : _vThreadEvents) {
            threadEvent->wait();
        }
    }
    
    
protected:
    bool _threadAbortFlag;
    vector<std::shared_ptr<Event>> _vThreadEvents;
    
private:
    virtual void OnBegin() = 0;
    virtual void OnProc() = 0;
    virtual void OnError(Exception& e) = 0;
    virtual void OnEnd() = 0;
    virtual void OnStop() = 0;//֪ͨ OnProc �������
};

#endif // __mkThread