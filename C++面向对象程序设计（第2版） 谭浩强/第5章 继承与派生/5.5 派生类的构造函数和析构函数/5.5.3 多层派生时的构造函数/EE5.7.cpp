//多级派生情况下派生类的构造函数。
#include<iostream>
#include<string>
using namespace std;
class Student                     //声明基类
  {public:                        //公用部分
     Student(int n,string nam)     //基类构造函数
       {num=n;
        name=nam;
       }
     void display()               //输出基类数据成员
       {cout<<"num:"<<num<<endl;
          cout<<"name:"<<name<<endl;
       }
   protected:                     //保护部分
     int num;                     //基类有两个数据成员
     string name;
  };

class Student1:public Student     //声明公用派生类Student1
  {public:
     Student1(int n,string nam,int a):Student(n,nam)  //派生类构造函数
     {age=a;}                     //在此处只对派生类新增的数据成员初始化
     void show()                  //输出num,name和age
       {display();                //输出num和name
        cout<<"age:"<<age<<endl;
       }
     private:                     //派生类的私有数据
       int age;                   //增加一个数据成员
  };

class Student2:public Student1    //声明间接公用派生类student2
  {public:
   //下面是间接派生类构造函数
   Student2(int n,string nam,int a,int s):Student1(n,nam,a)
   {score=s;}
   void show_all()                //输出全部数据成员
   {show();                       //输出num和name
    cout<<"score:"<<score<<endl;  //输出age
   }
   private:
     int score;                   //增加一个数据成员
  };

int main()
  {Student2 stud(10010,"Li",17,89);
   stud.show_all();               //输出学生的全部数据
   return 0;
  }
