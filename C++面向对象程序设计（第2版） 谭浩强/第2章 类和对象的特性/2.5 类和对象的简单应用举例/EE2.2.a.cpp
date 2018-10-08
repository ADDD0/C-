//用上例中的Time类，定义多个类对象，分别输入和输出各对象中的时间（时：分：秒）。
#include<iostream>
using namespace std;
class Time                                          //声明Time类
{public:
  int hour;
  int minute;
  int sec;
};
int main()
{Time t1;                                           //定义对象t1
 cin>>t1.hour;                                      //向t1的数据成员输入数据
 cin>>t1.minute;
 cin>>t1.sec;
 cout<<t1.hour<<":"<<t1.minute<<":"<<t1.sec<<endl;  //输出t1中数据成员的值
 Time t2;                                           //定义对象t2
 cin>>t2.hour;                                      //向t2的数据成员输入数据
 cin>>t2.minute;
 cin>>t2.sec;
 cout<<t2.hour<<":"<<t2.minute<<":"<<t2.sec<<endl;  //输出t2中数据成员的值
 return 0;
}