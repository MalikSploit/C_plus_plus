//
// Created by root on 12/14/23.
//
#include <iostream>

class M {
public:
    M() {
        std::cout << "M::M()" << std::endl;
    }
    ~M() {
        std::cout << "M::~M()" << std::endl;
    }
    M(const M&) {
        std::cout << "M::M(const M&)" << std::endl;
    }
    M & operator=(const M& other){
        if (this != &other){
            std::cout << "M operator= called" << std::endl;
        }
        return *this;
    }

};

class A {
private:
    M miniM;
public:
    A() {
        std::cout << "A::A()" << std::endl;
    }
    ~A() {
        std::cout << "A::~A()" << std::endl;
    }
    A(const A& a) : miniM(a.miniM){
        std::cout << "A::A(const A&)" << std::endl;
    }
    A & operator=(const A& other){
        if (this != &other){
            std::cout << "A operator= called" << std::endl;
        }
        return *this;
    }
};

class F : public M {
public:
    F() {
        std::cout << "F::F()" << std::endl;
    }
    ~F() {
        std::cout << "F::~F()" << std::endl;
    }
    F(const F& f) : M(f){
      std::cout << "F::F(const F&)" << std::endl;
    }
    F& operator=(const F& other) {
        if (this != &other) {
            std::cout << "F operator= called" << std::endl;
            M::operator=(other);
        }
        return *this;
    }
};

int main(int, char**) {

    /*F f1;
    F f2 = f1;

    f1 = f2;*/

    A a1;
    std::cout << std::endl;
    A a2 = a1;

    return 0;
}