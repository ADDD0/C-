//访问公有基类的成员。
#include<iostream>
using namespace std;
class Student                         //声明基类
  {public:                            //基类公用成员
     void get_value()                 //输入基类数据的成员函数
       {cin>>num>>name>>sex;}
     void display()                   //输出基类数据的成员函数
       {cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"sex:"<<sex<<endl;}
   private:                           //基类私有成员
     int num;
     string name;
     char sex;
  };

class Student1:public Student         //以public方式声明派生类Student1
  {public:
    void get_value_1()
      {cin>>age>>addr;}
    void display_1()
      {cout<<"age:"<<age<<endl;       //引用派生类的私有成员,正确
       cout<<"address:"<<addr<<endl;  //引用派生类的私有成员,正确
      }
     private:
      int age;
      string addr;
  };

int main()
  { Student1 stud;       //定义派生类Student1的对象stud
    stud.get_value();    //调用基类的公用成员函数,输入基类中3个数据成员的值
    stud.get_value_1();  //调用派生类的公用成员函数,输入派生类两个数据成员的值
    stud.display();      //调用基类的公用成员函数,输出基类中3个数据成员的值
    stud.display_1();    //调用派生类的公用成员函数,输出派生类中两个数据成员的值
    return 0;
  }