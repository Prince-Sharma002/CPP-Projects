#include <iostream>
#include <fstream>
using namespace std;

class BaseClass{
    public:
    void fun1(){
       std::cout << "this is function 1"; 
    }
};

class DerivedClass: public BaseClass{
    public:
    void fun1(){
        std::cout << "this is function 2"; 
    }
};

int main(){
    // BaseClass obj =  BaseClass();
    // DerivedClass obj2 = DerivedClass();
    // obj.fun1();
    // obj2.fun1();

    int x = 20;
    std::cout << 20.2 + x  << std::endl;

    int y = 20.8;
    std::cout << int(y) ;

    return 0;
}