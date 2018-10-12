//统计学生平均成绩。使用静态成员函数。
#include<iostream>
using namespace std;
class Student                 //定义Student类
  {public:
     Student(int n,int a,float s):num(n),age(a),score(s){}  //定义构造函数
     void total();            //声明成员函数
     static float average();  //声明静态成员函数
   private:
     int num;
     int age;
     float score;
     static float sum;        //静态数据成员sum(总分)
     static int count;        //静态数据成员count(计数)
  };

void Student::total()         //定义非静态成员函数
  {sum+=score;                //累加总分
   count++;                   //累计已统计的人数
  }

float Student::average()      //定义静态成员函数
  {return(sum/count);
  }

float Student::sum=0;         //对静态数据成员初始化
int Student::count=0;         //对静态数据成员初始化

int main()
  {Student stud[3]={          //定义对象数组并初始化
      Student(1001,18,70),
      Student(1002,19,78),
      Student(1005,20,98),
    };
   int n;
   cout<<"please input the number of students:";
   cin>>n;                    //输入需要求前面多少名学生的平均成绩
   for(int i=0;i<n;i++)       //调用3次total函数
     stud[i].total();
   cout<<"the average score of "<<n<<" students is "<<Student::average()<<endl;
                              //调用静态成员函数
   return 0;
}