//header1.h(头文件1)
#include<string>
#include<cmath>
using namespace std;
class Student                  //声明Student类
  {public:
     Student(int n,string nam,int a)
       {num=n;name=nam;age=a;}
     void get_data();
   private:
     int num;
     string name;
     int age;
  };
void Student::get_data()       //成员函数定义
  {cout<<num<<" "<<name<<" "<<age<<endl;
  }
double fun(double a,double b)  //定义全局函数(即外部函数)
  {return sqrt(a+b);}
