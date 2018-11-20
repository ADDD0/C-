//将例5.1中的公用继承方式改为用私有继承方式（基类Student不改）。
#include<iostream>
using namespace std;
class Student                           //声明基类
  {public:                              //基类公用成员
     void get_value()                   //输入基类数据的成员函数
       {cin>>num>>name>>sex;}
     void display()                     //输出基类数据的成员函数
       {cout<<"num:"<<num<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"sex:"<<sex<<endl;}
   private:                             //基类私有成员
     int num;
     string name;
     char sex;
  };

class Student1:private Student           //用私有继承方式声明派生类Student1
  {public:
     void get_value_1()   //输入5个数据的函数
       {get_value();      //调用基类的公用函数输入基类3个数据
        cin>>age>>addr;}  //输入派生类两个数据
     void display_1()     //输出5个数据成员的值
       {display();        //调用基类的公用成员函数,输出3个数据成员的值
        cout<<"age:"<<age<<endl;        //输出派生类的私有数据成员age
        cout<<"address:"<<addr<<endl;}  //输出派生类的私有数据成员addr
   private:
      int age;
      string addr;
  };

int main()
  {Student1 stud1;
   stud1.get_value_1();   //get_value_1是派生类Student1类的公用函数
   stud1.display_1();     //display_1是派生类Student1类的公用函数
   return 0;
  }