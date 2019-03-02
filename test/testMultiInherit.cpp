#include <iostream>

class A{
    public:
        virtual void afunc()=0;
};

class B:public A{
};

class C:public B{
    public:
    void afunc(){
        std::cout<<"adas"<<std::endl;
    }
};

int main(){
    C cc;
    cc.afunc();
    return 0;
}