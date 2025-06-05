#pragma once

#include "BaseTest.h"
#include "Pair.h"

#define LOG_CLASS Test

//并不限定实际数据类型的模板函数
template<typename T>
T Add(T a,T b)
{
    return a+b;
}

class Test:public BaseTest
{
public:
    Test(int argc,const char** argv);
    ~Test();
    virtual int operator()()override;
private:
    
};
