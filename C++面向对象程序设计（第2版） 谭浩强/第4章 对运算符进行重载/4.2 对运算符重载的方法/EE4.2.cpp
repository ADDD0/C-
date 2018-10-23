//改写例4.1，对运算符“+”实行重载，使之能用于两个复数相加。
#include<iostream>
using namespace std;
class Complex
  {public:
     Complex(){real=0;imag=0;}
     Complex(double r,double i){real=r;imag=i;}
     Complex operator+(Complex &c2);          //声明重载运算符"+"的函数
     void display();
   private:
     double real;
     double imag;
  };

Complex Complex::operator+(Complex &c2)       //定义重载运算符"+"的函数
  { Complex c;
    c.real=real+c2.real;                      //实现两个复数的实部相加
    c.imag=imag+c2.imag;                      //实现两个复数的虚部相加
    return c;}

void Complex::display()
  { cout<<"("<<real<<","<<imag<<"i)"<<endl;}  //输出复数形式

int main()
  { Complex c1(3,4),c2(5,-10),c3;
    c3=c1+c2;                                 //运算符"+"用于复数运算
    cout<<"c1="; c1.display();                //输出c1
    cout<<"c2="; c2.display();                //输出c2
    cout<<"c1+c2="; c3.display();             //输出c1+c2
    return 0;
  }