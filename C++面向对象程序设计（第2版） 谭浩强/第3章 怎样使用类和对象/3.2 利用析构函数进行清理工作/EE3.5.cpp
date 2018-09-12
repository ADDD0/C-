//包含构造函数和析构函数的C++程序。
#include<string>
#include<iostream>
using namespace std;
class Student                               //声明Student类
  {public:
     Student(int n,string nam,char s)       //定义有参数的构造函数
       {num=n;
        name=nam;
        sex=s;
        cout<<"Constructor called."<<endl;  //输出有关信息
       }
     ~Student()                             //定义析构函数
       {cout<<"Destructor called."<<endl;   //输出指定的信息
       }
     void display()                         //定义成员函数
       {cout<<"num: "<<num<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"sex: "<<sex<<endl<<endl;
       }
   private:
     int num;
     string name;
     char sex;
  };

int main()                                  //主函数
  {Student stud1(10010,"Wang_li",'f');      //建立对象stud1
   stud1.display();                         //输出学生1的数据
   Student stud2(10011,"Zhang_fan",'m');    //定义对象stud2
   stud2.display();                         //输出学生2的数据
   return 0;
  }