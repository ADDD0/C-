//声明一个教师（Teacher）类和一个学生（Student）类，用多重继承的方式声明一个
//在职研究生（Graduate）派生类（在职教师攻读研究生）。教师类中包括数据成员name
//（姓名）、age（年龄）、title（职称）。学生类中包括数据成员name1（姓名）、sex
//（性别）、score（成绩）。在定义派生类对象时给出初始化的数据，然后输出这些数据。
#include<iostream>
#include<string>
using namespace std;
class Teacher                                 //声明类Teacher(教师)类
  {public:                                    //公用部分
     Teacher(string nam,int a,string t)       //构造函数
       {name=nam;
        age=a;
        title=t;}
     void display()                           //输出教师有关数据
       {cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
        cout<<"title:"<<title<<endl;
       }
   protected:                                 //保护部分
     string name;
     int age;
     string title;                            //职称
  };

class Student                                 //定义类Student(学生)
  {public:
     Student(string nam,char s,float sco)     //构造函数
     {name1=nam;
      sex=s;
      score=sco;}
     void display1()                          //定义输出学生有关数据的函数
     {cout<<"name:"<<name1<<endl;
      cout<<"sex:"<<sex<<endl;
      cout<<"score:"<<score<<endl;
     }
   protected:                                 //保护部分
     string name1;
     char sex;
     float score;                             //成绩
  };

class Graduate:public Teacher,public Student  //声明多重派生类Graduate
  {public:
     Graduate(string nam,int a,char s,string t,float sco,float w):
        Teacher(nam,a,t),Student(nam,s,sco),wage(w){}
     void show()                              //输出研究生的有关数据
     {cout<<"name:"<<name<<endl;
      cout<<"age:"<<age<<endl;
      cout<<"sex:"<<sex<<endl;
      cout<<"score:"<<score<<endl;
      cout<<"title:"<<title<<endl;
      cout<<"wages:"<<wage<<endl;
   }
   private:
     float wage;                              //津贴
  };

int main()
  {Graduate grad1("Wang_li",24,'f',"assistant",89.5,2400);
   grad1.show();
   return 0;
  }