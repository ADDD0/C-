//将一个double数据与Complex类数据相加。
#include<iostream>
using namespace std;
class Complex
  {public:
     Complex(){real=0;imag=0;}
     Complex(double r,double i){real=r;imag=i;}
     operator double() {return real;}  //定义类型转换函数
   private:
     double real;
     double imag;
  };
  
int main()
  {Complex c1(3,4),c2(5,-10),c3;       //建立3个Complex类对象
   double d;
   d=2.5+c1;                           //要求将一个double数据与Complex类数据相加
   cout<<d<<endl;
   return 0;
  }