/**
 * 定义一个复数类Complex，重载运算符“+”，使之能用于复数的加法运算。
 * 将运算符函数重载为非成员，非友元的普通函数。编程序，求两个复数之和。
 */
#include <iostream>

using namespace std;

class Complex {
    public:
        Complex() {real=imag=0;}
        Complex(double r, double i): real(r), imag(i) {}

        double real, imag;

        void display();
};

Complex operator + (Complex &c1, Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

void Complex::display() {
    cout << real << showpos << imag << 'i' << endl;
}

int main() {
    Complex c1(3, 4), c2(5, -10);

    c1 = c1 + c2;
    c1.display();
    return 0;
}