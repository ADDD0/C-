//使用对象的引用，输出时间（时、分、秒）。
#include<iostream>
using namespace std;
class Time
  {public:
     Time(int,int,int);
     int hour;
     int minute;
     int sec;
  };

Time::Time(int h,int m,int s)  //定义构造函数
  {hour=h;
   minute=m;
   sec=s;
  }

void fun(Time &t)              //形参t是Time类对象的引用
  {t.hour=18;
  }

int main()
  {Time t1(10,13,56);          //t1是Time类对象
   fun(t1);
   //实参是Time类对象,可以通过引用来修改实参t1的值
   cout<<t1.hour<<endl;        //输出t1.hour的值为18
   return 0;
  }