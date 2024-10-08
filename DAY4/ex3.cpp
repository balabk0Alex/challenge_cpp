/*Создайте трехуровневую иерархию классов, содержащих конструкторы по
умолчанию и деструкторы; и те и другие должны выводить сообщения в cout.
Убедитесь в том, что для объекта, находящегося на последней ступени иерар­
хии, автоматически вызываются все три конструктора и деструктора. Объяс­
ните порядок вызовов.*/
#include <iostream>

class A
{
public:
    A() { std::cout << "A::A()" << std::endl;}
    ~A() { std::cout << "A::~A()" << std::endl ;}
};

class B:public A
{
public:
    B() {std::cout << "B::B()" << std::endl;}
    ~B() { std::cout << "B::~B()" << std::endl;}
};

class C:public B
{
public:
    C(){std::cout << "C::C()" << std::endl;}
    ~C() {std::cout << "C::~C()" << std::endl;}
};

int main()
{
    C c;
}
