/**
 * 定义一个复数类Complex，重载运算符“+”，使之能用于复数的加法运算。
 * 参加运算的两个运算量可以都是类对象，也可以其中有一个是整数，顺序任意。
 * 如c1+c2，i+c1，c1+i均合法（设i为整数，c1，c2为复数）。
 * 编程序，分别求两个复数之和、整数和复数之和。
 */
#include <iostream>

using namespace std;

class Complex {
    public:
        Complex(double r=0.0, double i=0.0): real(r), imag(i) {};
        friend Complex operator + (Complex, Complex);
        friend Complex operator + (Complex, int);
        void display();
    private:
        double real, imag;
};

Complex operator + (Complex x, Complex y) {
    return Complex(x.real + y.real, x.imag + y.imag);
}

Complex operator + (Complex x, int y) {
    return Complex(x.real + y, x.imag);
}

void Complex::display() {
    cout << noshowpos << real << showpos << imag << 'i' << endl;
}

int main() {
    Complex c1(3, 4), c2(5, -10);
    int i=6;

    c1 = c1 + c2, c1.display();
    c1 = c1 + i, c1.display();
    c2 = i + c2, c2.display();
    return 0;
}