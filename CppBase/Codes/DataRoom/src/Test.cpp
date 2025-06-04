/*
 * @Author: EST 363023987@qq.com
 * @Date: 2025-06-04 09:56:36
 * @LastEditors: EST 363023987@qq.com
 * @LastEditTime: 2025-06-04 13:56:53
 * @FilePath: \Codes\DataRoom\src\Test.cpp
 */
#include "Test.h"

Test::Test(int argc, const char **argv)
    :BaseTest(argc,argv)
{
}

Test::~Test()
{
}

int Test::operator()()
{
    _type_sizeof();
    return 0;
}

template<typename T>
void Print_Size(const std::string& str)
{
    std::cout<<str<<" size : "<<sizeof(T)<<"\n";
}

void Test::_type_sizeof()
{
    Print_Size<int>("int");
    Print_Size<short>("short");
    Print_Size<long>("long");
    Print_Size<char>("char");
    Print_Size<double>("double");
    Print_Size<float>("float");
    Print_Size<char>("char");

}