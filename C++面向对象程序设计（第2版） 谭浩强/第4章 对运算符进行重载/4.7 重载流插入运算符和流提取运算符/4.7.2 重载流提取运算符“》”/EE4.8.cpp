//在例4.7的基础上，增加重载流提取运算符“>>”，用“cin>>”输入复数，用“cout<<”输出复数。
#include<iostream>
using namespace std;
class Complex
  {public:
     friend ostream& operator <<(ostream&,Complex&);//声明友元重载运算符"<<"函数
	 friend istream& operator >>(istream&,Complex&);//声明友元重载运算符">>"函数
   private:
     double real;
	 double imag;
  };
ostream& operator <<(ostream& output,Complex& c)    //定义重载运算符"<<"函数
  {output<<"("<<c.real<<"+"<<c.imag<<"i)";
   return output;
  }
istream& operator >>(istream& input,Complex& c)     //定义重载运算符">>"函数
  {cout<<"input real part and imaginary part of complex number:";
   input>>c.real>>c.imag;
   return input;
  }
int main()
  {Complex c1,c2;
   cin>>c1>>c2;
   cout<<"c1="<<c1<<endl;
   cout<<"c2="<<c2<<endl;
   return 0;
  }