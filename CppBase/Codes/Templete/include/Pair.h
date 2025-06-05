#pragma once

template<typename F,typename S>
class Pair
{

public:
    Pair(F f,S s):_f(f),_s(s){}
    ~Pair(){}
    void Print()
    {
        std::cout << _f<<"  "<< _s <<"\n"<<std::endl;
    }
private:
    F _f;
    S _s;
};


