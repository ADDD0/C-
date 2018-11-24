/**
 * 声明一个复数类Complex，重载运算符“+”，“-”，“*”，“/”，使之能用于
 * 复数的加、减、乘、除，运算符重载函数作为Complex类的成员函数。
 * 编程序，分别求两个复数之和、差、积和商。
 * 本题是《C++面向对象程序设计》第4章第2题。
 * 请思考：你编的程序能否用于一个整数与一个复数的算术运算？如4+(5-2i)。
 */
#include <iostream>

using namespace std;

class Complex {
    public:
        Complex(double r=0.0, double i=0.0): real(r), imag(i) {};
        void setComplex();
        void display();

        Complex operator + (const Complex &) const;
        Complex operator - (const Complex &) const;
        Complex operator * (const Complex &) const;
        Complex operator / (const Complex &) const;
    private:
        double real, imag;
};

void Complex::setComplex() {
    cout << "Please input two real numbers:";
    cin >> real >> imag;
}

void Complex::display() {
    cout << noshowpos << real << showpos << imag << 'i' << endl;
}

Complex Complex::operator +(const Complex &y) const {
    return Complex(real + y.real, imag + y.imag);
}

Complex Complex::operator -(const Complex &y) const {
    return Complex(real - y.real, imag - y.imag);
}

Complex Complex::operator *(const Complex &y) const {
    return Complex(real * y.real - imag * y.imag,
                   real * y.imag + imag * y.real);
}

Complex Complex::operator /(const Complex &y) const {
    if (!y.real && !y.imag) {
        cout << "The divisor can't be 0." << endl;
        return Complex();
    } else if (!y.imag)
        return Complex(real / y.real, imag / y.real);
    return (*this) * Complex(y.real, -y.imag) /
           Complex(y.real * y.real + y.imag * y.imag, 0);
}

int main() {
    Complex c1, c2, c3;

    c1.setComplex();
    c2.setComplex();
    c3 = c1 + c2, c3.display();
    c3 = c1 - c2, c3.display();
    c3 = c1 * c2, c3.display();
    c3 = c1 / c2, c3.display();
    return 0;
}