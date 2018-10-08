//可以对上面的程序做一些修改，数据成员的值不再由键盘输入，而在调用函数时由实参
//给出，并在函数中使用默认参数。
#include<iostream>
using namespace std;
class Time
{public:
  int hour;
  int minute;
  int sec;
};

int main()
{
  void set_time(Time&,int hour=0,int minute=0,int sec=0);  //函数声明,指定了
                                                           //默认参数
  void show_time(Time&);                                   //函数声明
  Time t1;
  set_time(t1,12,23,34);                            //通过实参传递时分秒的值
  show_time(t1);
  Time t2;
  set_time(t2);                                     //使用默认的时分秒的值
  show_time(t2);
  return 0;
}

void set_time(Time& t,int hour,int minute,int sec)  //定义函数时不必再指定了默认参数
{
  t.hour=hour;
  t.minute=minute;
  t.sec=sec;
}

void show_time(Time& t)
{
  cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
}