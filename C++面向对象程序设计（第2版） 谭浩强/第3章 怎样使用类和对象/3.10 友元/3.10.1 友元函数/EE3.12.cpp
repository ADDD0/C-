//友元函数的简单例子。
#include<iostream>
using namespace std;
class Time
  {public:
     Time(int,int,int);            //声明构造函数
     friend void display(Time &);  //声明display函数为Time类的友元函数
   private:                        //以下数据是私有数据成员
     int hour;
     int minute;
     int sec;
  };

Time::Time(int h,int m,int s)      //定义构造函数,给hour,minute,sec赋初值
  {hour=h;
   minute=m;
   sec=s;
  }

void display(Time& t)              //这是普通函数,形参t是Time类对象的引用
  {cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;}

int main()
  { Time t1(10,13,56);
    display(t1);                   //调用display函数,实参t1是Time类对象
    return 0;
  }