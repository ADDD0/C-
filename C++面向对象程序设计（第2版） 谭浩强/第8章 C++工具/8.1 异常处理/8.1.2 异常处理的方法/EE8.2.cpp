//在函数嵌套的情况下检测异常处理。
#include<iostream>
using namespace std;
int main()
{void f1();
 try
   {f1();}     //调用f1()
 catch(double)
   {cout<<"ERROR0!"<<endl;}
 cout<<"end0"<<endl;
 return 0;
}

void f1()      //定义f1函数
{void f2();
 try
   {f2();}     //调用f2()
 catch(char)
   {cout<<"ERROR1!"<<endl;}
 cout<<"end1"<<endl;
}

void f2()      //定义f2函数
{void f3();
try
  {f3();}      //调用f3()
catch(int)
  {cout<<"ERROR2!"<<endl;}
cout<<"end2"<<endl;
}

void f3()      //定义f3函数
{double a=0;
 try
   {throw a;}  //抛出double类型异常
 catch(float)
   {cout<<"ERROR3!"<<endl;}
 cout<<"end3"<<endl;
}