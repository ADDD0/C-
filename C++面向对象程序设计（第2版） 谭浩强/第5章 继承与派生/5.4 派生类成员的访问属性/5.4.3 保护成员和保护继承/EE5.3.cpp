//在派生类中引用保护成员。
#include<iostream>
#include<string>
using namespace std;
class Student                     //声明基类
  {public:                        //基类无公用成员

   protected:
     int num;
     string name;
     char sex;
  };

class Student1:protected Student  //用protected方式声明派生类Student1
  {public:
     void get_value1();           //派生类公用成员函数
     void display1();             //派生类公用成员函数
   private:
     int age;                     //派生类私有数据成员
     string addr;                 //派生类私有数据成员
  };
void Student1::get_value1()       //定义派生类公用成员函数
  {cin>>num>>name>>sex;           //输入保护基类数据成员
   cin>>age>>addr;}               //输入派生类数据成员

void Student1::display1()         //定义派生类公用成员函数
  {cout<<"num:"<<num<<endl;       //引用基类的保护成员
   cout<<"name:"<<name<<endl;     //引用基类的保护成员
   cout<<"sex:"<<sex<<endl;       //引用基类的保护成员
   cout<<"age:"<<age<<endl;       //引用派生类的私有成员
   cout<<"address:"<<addr<<endl;  //引用派生类的私有成员
  }

int main()
  {Student1 stud1;      //stud1是派生类Student1类的对象
   stud1.get_value1();  //get_value1是派生类中的公用成员函数,输入数据
   stud1.display1();    //display1是派生类中的公用成员函数,输出数据
   return 0;
  }