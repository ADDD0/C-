//声明一个基类Student（学生），再声明Student类的公用派生类Graduate（研究生），
//用指向基类对象的指针输出数据。
#include<iostream>
#include<string>
using namespace std;
class Student                               //声明Student类
  {public:
     Student(int,string,float);             //声明构造函数
     void display();                        //声明输出函数
   private:
     int num;
     string name;
     float score;
  };

Student::Student(int n,string nam,float s)  //定义构造函数
  {num=n;
   name=nam;
   score=s;
  }

void Student::display()                     //定义输出函数
  {cout<<endl<<"num:"<<num<<endl;
   cout<<"name:"<<name<<endl;
   cout<<"score:"<<score<<endl;
  }

class Graduate:public Student               //声明公用派生类Graduate
  {public:
     Graduate(int,string,float,float);      //声明构造函数
     void display();                        //声明构造函数
   private:
     float wage;                            //津贴
  };

Graduate::Graduate(int n,string nam,float s,float w):Student(n,nam,s),
                  wage(w){}                 //定义构造函数
void Graduate::display()                    //定义输出函数
  {Student::display();                      //调用Student类的display函数
   cout<<"wage="<<wage<<endl;
  }

int main()
  {Student stud1(1001,"Li",87.5);           //定义Student类对象stud1
   Graduate grad1(2001,"Wang",98.5,1000);   //定义Graduate类对象grad1
   Student *pt=&stud1;          //定义指向Student类对象的指针并指向stud1
   pt->display();                           //调用stud1.display函数
   pt=&grad1;                               //指针指向grad1
   pt->display();                           //调用grad1.display函数
   return 0;
  }