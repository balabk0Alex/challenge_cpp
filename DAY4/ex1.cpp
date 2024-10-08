/*Измените класс из примера Саг.срр так, чтобы он наследовал от класса Vehicle.
Включите в Vehicle какие-нибудь функции и добавьте конструктор, отлич­
ный от конструктора по умолчанию; этот конструктор должен вызываться
в конструкторе Саг.*/

#include <iostream>

class Vehicle
{
public:
    Vehicle(char * name, int n):name_driver(name), number_transport(n)
    {

    }

    void get_name()
    {
        std::cout << name_driver << std::endl;
    }

private:
    char * name_driver;
    int number_transport;
};

class Engine{
public:
    void start() const {}
    void rev() const {}
    void stop() const {}
};


class Wheel{
public:
    void inflate(int psi) const {}
};

class Window{
public:
    void rollup() const {}
    void rolldown() const {}
};

class Door{
public:
    Window window;
    void open() const {}
    void close() const {}
};

class Car: public Vehicle
{
public:
    Car(char * name):Vehicle(name, 1)
    {
    }
    Engine engine;
    Wheel wheel[4];
    Door left, right;
};

int main()
{
    Car car("Alex");
    car.left.window.rollup();
    car.wheel[0].inflate(72);

    car.get_name();
}
