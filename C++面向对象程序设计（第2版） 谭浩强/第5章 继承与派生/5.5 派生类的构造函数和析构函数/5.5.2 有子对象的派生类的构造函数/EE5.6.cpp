//包含子对象的派生类的构造函数。
#include<iostream>
#include<string>
using namespace std;
class Student                                //声明基类
  {public:                                   //公用部分
     Student(int n,string nam)               //基类构造函数,与例5.5相同
     {num=n;
      name=nam;
     }
     void display()                          //成员函数,输出基类数据成员
       {cout<<"num:"<<num<<endl<<"name:"<<name<<endl;}
   protected:                                //保护部分
     int num;
     string name;
  };

class Student1:public Student                //声明公用派生类
  {public:
     Student1(int n,string nam,int n1,string nam1,int a,string ad)
       :Student(n,nam),monitor(n1,nam1)      //派生类构造函数
     {age=a;
      addr=ad;
     }
     void show()
       {cout<<"This student is:"<<endl;
        display();                           //输出num和name
        cout<<"age:"<<age<<endl;             //输出age
        cout<<"address:"<<addr<<endl<<endl;  //输出addr
       }
     void show_monitor()
       {cout<<endl<<"Class monitor is:"<<endl;
        monitor.display();                   //调用基类成员函数
       }
     private:                                //派生类的私有数据
     Student monitor;                        //定义子对象(班长)
     int age;
     string addr;
  };

int main()
  {Student1 stud1(10010,"Wang_li",10001,"Li_jun",19,"115 Beijing Road,Shanghai");
   stud1.show();                             //输出学生的数据
   stud1.show_monitor();                     //输出子对象的数据
   return 0;
  }