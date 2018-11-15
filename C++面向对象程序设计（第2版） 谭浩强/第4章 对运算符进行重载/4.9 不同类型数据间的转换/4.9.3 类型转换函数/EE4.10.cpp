//包含转换构造函数、运算符重载函数和类型转换函数的程序。
#include<iostream>
using namespace std;
class Complex
  {public:
     Complex(){real=0;imag=0;}                   //默认构造函数,无形参
	 Complex(double r){real=r;imag=0;}           //转换构造函数,一个形参
     Complex(double r,double i){real=r;imag=i;}  //实现初始化的构造函数,两个形参
     friend Complex operator +(Complex c1,Complex c2);//重载运算符"+"的友元函数
	 void display();
   private:
     double real;
     double imag;
  };
  
Complex operator +(Complex c1,Complex c2)        //定义运算符"+"重载函数
  {return Complex(c1.real+c2.real,c1.imag+c2.imag);}

void Complex::display()                          //定义输出函数
  {cout<<"("<<real<<","<<imag<<"i)"<<endl;}

int main()
  {Complex c1(3,4),c2(5,-10),c3;                 //建立3个对象
   c3=c1+2.5;                                    //复数与double数据相加
   c3.display();
   return 0;
  }