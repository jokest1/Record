#include <iostream>
#include "BaseTest.h"
#include "Test.h"

template<typename T>
int exe(int argc,const char* argv[])
{
    return T(argc, argv)();
}


int main(int argc,const char* argv[])
{
    int ret = 0;
#ifdef LOG_CLASS
    ret =exe<LOG_CLASS>(argc,argv);
#else
    ret =exe<BaseTest>(argc,argv);
#endif
    return ret;
}