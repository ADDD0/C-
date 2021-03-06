//在例4.5程序的基础上增加对后置自增运算符的重载。
#include<iostream>
using namespace std;
class Time
  {public:
     Time(){minute=0;sec=0;}
     Time(int m,int s):minute(m),sec(s){}
     Time operator++();     //声明前置自增运算符"++"重载函数
     Time operator++(int);  //声明后置自增运算符"++"重载函数
     void display(){cout<<minute<<":"<<sec<<endl;}
   private:
     int minute;
     int sec;
  };

Time Time::operator++()     //定义前置自增运算符"++"重载函数
  {if(++sec>=60)
     {sec-=60;
      ++minute;}
   return *this;            //返回自加后的当前对象
  }

Time Time::operator++(int)  //定义后置自增运算符"++"重载函数
  {Time temp(*this);        //建立临时对象temp
   sec++;
   if(sec>=60)
     {sec-=60;
      ++minute;}
   return temp;             //返回的是自加前的对象
  }

int main()
  {Time time1(34,59),time2;
   cout<<"time1 : ";
   time1.display();
   ++time1;
   cout<<"++time1: ";
   time1.display();
   time2=time1++;           //将自加前的对象的值赋给time2
   cout<<"time1++: ";
   time1.display();
   cout<<" time2: ";
   time2.display();         //输出time2对象的值
  }