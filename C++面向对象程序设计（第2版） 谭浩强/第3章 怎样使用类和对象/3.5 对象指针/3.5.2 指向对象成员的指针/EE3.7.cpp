//用对象指针方法输出时、分、秒。
#include<iostream>
using namespace std;
class Time
  {public:
     Time(int,int,int);        //声明结构函数
     int hour;
     int minute;
     int sec;
     void get_time();          //声明公有成员函数
  };

Time::Time(int h,int m,int s)  //定义结构函数
  {hour=h;
   minute=m;
   sec=s;
  }

void Time::get_time()          //定义公有成员函数
  {cout<<hour<<":"<<minute<<":"<<sec<<endl;
  }

int main()
  {Time t1(10,13,56);          //定义Time类对象t1并初始化
   int *p1=&t1.hour;           //定义指向整型数据的指针变量p1,并使p1指向t1.hour
   cout<<*p1<<endl;            //输出p1所指的数据成员t1.hour
   t1.get_time();              //调用对象t1的公用成员函数get_time
   Time *p2=&t1;               //定义指向Time类对象的指针变量p2,并使p2指向t1
   p2->get_time();             //调用p2所指向对象(即t1)的get_time函数
   void(Time::*p3)();          //定义指向Time类公用成员函数的指针变量p3
   p3=&Time::get_time;         //使p3指向Time类公用成员函数get_time
   (t1.*p3)();                 //调用对象t1中p3所指的成员函数(即t1.get_time())
   return 0;
  }