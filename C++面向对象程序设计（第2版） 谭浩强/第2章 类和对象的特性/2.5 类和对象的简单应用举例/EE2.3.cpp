//将例2.2的程序改用含成员函数的类来处理。
#include<iostream>
using namespace std;
class Time              //声明Time类
  {public:
     void set_time();   //公用成员函数
     void show_time();  //公用成员函数
   private:             //数据成员为私有
     int hour;
     int minute;
     int sec;
  };

int main()
  {Time t1;             //定义对象t1
   t1.set_time();       //调用对象t1的成员函数set_time,向t1的数据成员输入数据
   t1.show_time();      //调用对象t1的成员函数show_time,输出t1的数据成员的值
   Time t2;             //定义对象t2
   t2.set_time();       //调用对象t2的成员函数set_time,向t2的数据成员输入数据
   t2.show_time();      //调用对象t2的成员函数show_time,输出t2的数据成员的值
   return 0;
  }

void Time::set_time()   //在类外定义set_time函数
  {cin>>hour;
   cin>>minute;
   cin>>sec;
  }

void Time::show_time()  //在类外定义show_time函数
  {cout<<hour<<":"<<minute<<":"<<sec<<endl;
  }