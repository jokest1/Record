#include "Test.h"
#include <type_traits>

Test::Test(int argc, const char **argv)
    :BaseTest(argc,argv)
{
}

Test::~Test()
{
}

//对每个参数非操作，然后再将这些操作&&
//(!args && ...) 相当于 !a && !b && ...
template<typename ...Args>
bool allNot(const Args&... args)
{
    return (!args && ...);
}

//二元左折叠求和
template<typename... Args>
auto allAdd(const Args&... args)
{
    return (0+...+args);//左折叠(a+b)+c;
}

//二元右折叠求积
template<typename... Args>
auto allMult(const Args&... args)
{
    return (...*args);
}

//条件编译整数
template <typename T>
//使用了std::enable_if(判断T的类型,函数的返回值)::type
typename std::enable_if<std::is_integral<T>::value,void>::type
printNumber(T value)
{
    std::cout<<"is integral:"<<value<<"\n"<<std::endl;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value,void>::type
printNumber(T value)
{
    std::cout<<"is float point:"<<value<<"\n"<<std::endl;
}

//这是一个类型萃取器
template<typename T>
class has_foo
{
//根据条件编译的大小来判断bool值
typedef char yes[2];
typedef char no[1];

//定义一个使用类和类成员指针的模板类
template<typename U,void(U::*)()>
struct SFINA{};

//实例化上班模板作为形参
template<typename U>
static yes& test(SFINA<U,&U::foo>*);

//使用参数包作为占位符
template<typename U>
static no& test(...);

public:
    //重载决议根据编译时具体使用的实例化模板来判断bool值
    static constexpr bool value = sizeof(test<T>(0)) == sizeof(yes);
};

template<typename T>
typename std::enable_if<has_foo<T>::value>
call_foo(T& o)
{
    o.foo();
    std::cout << "foo end\n"<<std::endl;
}

class hasFoo
{
public:
    void foo()
    {
        std::cout<<" foo call end\n"<<std::endl;
    }
};

class unhasFoo
{

};


template <typename T, typename = void>
struct has_non_void_type : std::false_type {};

template<typename T>
struct has_non_void_type<T,std::enable_if_t<!std::is_void_v<typename T::value_type>>>: std::true_type
{};

template<typename T,bool HashValueType = has_non_void_type<T>::value>
class TypePointer;

template<typename T>
class TypePointer<T,true>
{
public:
    static void print()
    {
        std::cout << "T has a member type 'value_type'." << std::endl;
    }
};

template<typename T>
class TypePointer<T,false>
{
public:
    static void print()
    {
        std::cout << "hello world! T does not have a member type 'value_type'." << std::endl;
    }
};

// 测试结构体
struct WithValueType{
    using value_type = int;
};

struct WithoutValueType{};

struct WithVoidValueType{
    using value_type = void;
};


int Test::operator()()
{
    Pair<int ,std::string> p_id(10,"10.0");
    p_id.Print();
    allNot(true,true,false);
    std::cout<<allAdd(1,2,3,4)<<std::endl;
    std::cout<<allMult(1,2,3,4)<<std::endl;
    printNumber(3);
    printNumber(3.14);

    hasFoo hf;
    call_foo(hf);
    //unhasFoo uhf;
    //call_foo(uhf);
    TypePointer<WithValueType>::print();
    TypePointer<WithoutValueType>::print();
    TypePointer<WithVoidValueType>::print();

    return 0;
}

