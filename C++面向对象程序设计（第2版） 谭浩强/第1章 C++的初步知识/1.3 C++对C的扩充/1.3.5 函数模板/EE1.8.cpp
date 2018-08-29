//将例1.6程序改为通过函数模板来实现。
#include<iostream>
using namespace std;
template<typename T>  //模板声明,其中T为类型参数
T max(T a,T b,T c)    //定义一个通用函数,用T作虚拟的类型名
  {if(b>a) a=b;
   if(c>a) a=c;
   return a;
  }

int main()
  {int i1=8,i2=5,i3=6,i;
   double d1=56.9,d2=90.765,d3=43.1,d;
   long g1=67843,g2=-456,g3=78123,g;
   i=max(i1,i2,i3);   //调用模板函数,此时T被int取代
   d=max(d1,d2,d3);   //调用模板函数,此时T被double取代
   g=max(g1,g2,g3);   //调用模板函数,此时T被long取代
   cout<<"i_max="<<i<<endl;
   cout<<"d_max="<<d<<endl;
   cout<<"g_max="<<g<<endl;
   return 0;
  }