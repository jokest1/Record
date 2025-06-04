#pragma once

#define LOG_CLASS Test
#include "BaseTest.h"

class Test:public BaseTest
{
public:
    Test(int argc,const char** argv);
    ~Test();
    virtual int operator()()override;
private:
    void _type_sizeof();
};

