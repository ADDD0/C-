//header2.h(头文件2)
#include<string>
#include<cmath>
using namespace std;
namespace ns2     //声明命名空间ns2
  {class Student  //在命名空间ns2内声明Student类
     {public:
        Student(int n,string nam,char s)
          {num=n;name=nam;sex=s;}
        void get_data();
      private:
        int num;
        string name;
        char sex;
     };
  void Student::get_data()
    {cout<<num<<" "<<name<<" "<<sex<<endl;
    }
  double fun(double a,double b)
    {return sqrt(a-b);}
  }