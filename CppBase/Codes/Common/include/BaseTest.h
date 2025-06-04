/*
 * @Author: EST 363023987@qq.com
 * @Date: 2025-05-30 15:38:47
 * @LastEditors: EST 363023987@qq.com
 * @LastEditTime: 2025-06-04 10:57:11
 * @FilePath: \Codes\BaseTest.h
 */
#pragma once

#include <iostream>
class BaseTest
{
public:
    BaseTest(int argc,const char** argv)
    : _argc(argc),_argv(argv){}
    virtual ~BaseTest()
    {}
    virtual int operator()()
    {
        std::cout<<"hello word!\n"<<std::endl;
        return 0;
    }
protected:
    int _argc;
    const char** _argv;
};

