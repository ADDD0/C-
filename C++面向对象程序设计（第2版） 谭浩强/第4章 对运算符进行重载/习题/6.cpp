/**
 * 请编写程序，处理一个复数与一个double数相加的运算，
 * 结果存放在一个double型的变量d1中，输出d1的值，再以复数形式输出此值。
 * 定义Complex（复数）类，在成员函数中包含重载类型转换运算符：
 * operator double(){return real;}
 */
#include <iostream>

using namespace std;

class Complex {
    public:
        Complex(double r=0.0, double i=0.0): real(r), imag(i) {};
        void display();

        friend Complex operator + (Complex &, double &);
        operator double() {return real;}
    private:
        double real, imag;
};

void Complex::display() {
    cout << noshowpos << real << showpos << imag << 'i' << endl;
}

Complex operator + (Complex &c, double &d) {
    return Complex(c.real + d, c.imag);
}

intmain() {
    Complex c(3, 4);
    double d1;

    d1 = c + 6.13;
    cout << d1 << endl;
    Complex(d1, 0).display();
    return 0;
}