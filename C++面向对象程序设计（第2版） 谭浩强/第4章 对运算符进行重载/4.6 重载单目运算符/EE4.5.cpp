//有一个Time类，包含数据成员minute（分）和sec（秒），模拟秒表，每次
//走一秒，满60秒进一分钟，此时秒又从0起算。要求输出分和秒的值。
#include<iostream>
using namespace std;
class Time
  {public:
     Time(){minute=0;sec=0;}                //默认构造函数
     Time(int m,int s):minute(m),sec(s){ }  //构造函数重载
     Time operator++();                     //声明运算符重载成员函数
     void display(){cout<<minute<<":"<<sec<<endl;}  //定义输出时间函数
   private:
     int minute;
     int sec;
  };
Time Time::operator++()                     //定义运算符重载成员函数
  {if(++sec>=60)
    {sec-=60;                               //满60秒进1分钟
     ++minute;}
     return *this;                          //返回当前对象值
  }
int main()
  {Time time1(34,0);
   for(int i=0;i<61;i++)
     {++time1;
      time1.display();}
   return 0;
  }