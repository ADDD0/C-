//header1.h(头文件1)
#include<string>
#include<cmath>
using namespace std;
namespace ns1                     //声明命名空间ns1
  {class Student                  //在命名空间ns1内声明Student类
     {public:
        Student(int n,string nam,int a)
          {num=n;name=nam;age=a;}
        void get_data();
      private:
        int num;
        string name;
        int age;
     };
  void Student::get_data()       //定义成员函数
    {cout<<num<<" "<<name<<" "<<age<<endl;
    }

  double fun(double a,double b)  //在命名空间ns1内定义fun函数
    {return sqrt(a+b);}
  }