#include <iostream>

class Complex_number
{
public:
    Complex_number(double Re = 0, double Im = 0):Im(Im), Re(Re){}

    //overload PLUS
    const Complex_number operator+(const Complex_number &rigth)
    {
        return Complex_number(Re + rigth.Re, Im + rigth.Im);
    }

    //overload MINUS
    const Complex_number operator-(const Complex_number &rigth)
    {
        return Complex_number(Re - rigth.Re, Im - rigth.Im);
    }

    //overload ASSIGN
    const Complex_number & operator=(const Complex_number &rigth)
    {
        Im = rigth.Im;
        Re = rigth.Re;

        return *this;
    }

    double outRe(){return  Re ;}
    double outIm() {return Im;}

    void setRe(double sRe){Re = sRe ;}

    void test_comp()
    {}


    double Re, Im;
};


class Integer_number : public Complex_number
{
public:
    Integer_number(int Num = 0) : Complex_number(Num, 0){}

    Integer_number & operator =(const Complex_number & right)
    {
        Re = right.Re;
        return *this;
    }

    void test_int()
    {

    }

private:
};

int main(int argc, char **argv) {

    Complex_number n1(1.1,1.4), n2(2.1,1.1), res;

    n2 = (n1 + n2);//опреатор присваивания для базового класса

    Integer_number n3(4), n4(5), res2;

    res2 = (n3+ n4);







}
