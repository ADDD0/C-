//定义简单的派生类的构造函数。
#include<iostream>
#include<string>
using namespace std;
class Student                          //声明基类Student
  {public:
     Student(int n,string nam,char s)  //定义基类构造函数
       {num=n;
        name=nam;
        sex=s; }
     ~Student(){ }                     //基类析构函数
   protected:                          //保护部分
     int num;
     string name;
     char sex;
  };

class Student1:public Student          //声明公用派生类
  {public:
     Student1(int n,string nam,char s,int a,string ad):Student(n,nam,s)
                                       //定义派生类构造函数
     {age=a;                           //在函数体中只对派生类新增的数据成员初始化
      addr=ad;
     }
     void show()
     {cout<<"num:"<<num<<endl;
      cout<<"name:"<<name<<endl;
      cout<<"sex:"<<sex<<endl;
      cout<<"age:"<<age<<endl;
      cout<<"address:"<<addr<<endl<<endl;
     }
     ~Student1(){}                     //派生类析构函数
   private:                            //派生类的私有部分
     int age;
     string addr;
  };

int main()                             //主函数
  {Student1 stud1(10010,"Wang-li",'f',19,"115 Beijing Road,Shanghai");
   Student1 stud2(10011,"Zhang-fan",'m',21,"213 Shanghai Road,Beijing" );
   stud1.show();                       //输出第一个学生的数据
   stud2.show();                       //输出第二个学生的数据
   return 0;
  }