<<<<<<< HEAD
//用上例中的Time类，定义多个类对象，分别输入和输出各对象中的时间（时：分：秒）。
=======
//用上例中的Time类，定义多个类对象，分别输入和输出各对象中的时间（时：分：秒）。
#include<iostream>
using namespace std;
class Time
  {public:
   int hour;
   int minute;
   int sec;
  };

int main()
  {void set_time(Time&,int hour=0,int minute=0,int sec=0);  //函数声明,指定了默认参数
   void show_time(Time&);  //函数声明
   Time t1;
   set_time(t1,12,23,34);  //通过实参传递时分秒的值
   show_time(t1);
   Time t2;
   set_time(t2);           //使用默认的时分秒的值
   show_time(t2);
   return 0;
  }

void set_time(Time& t,int hour,int minute,int sec)          //定义函数时不必再指定了默认参数
  {t.hour=hour;
   t.minute=minute;
   t.sec=sec;
  }

void show_time(Time& t)
  {cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
  }
>>>>>>> 5ff00451e42ea4eef5412d50b319d441ec05afd8
