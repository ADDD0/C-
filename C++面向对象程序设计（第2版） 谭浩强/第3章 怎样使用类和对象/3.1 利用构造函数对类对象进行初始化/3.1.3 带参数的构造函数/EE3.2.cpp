//有两个长方柱，其高、宽、长分别为（1）12，20，25；（2）10，14，20。
//求它们的体积。编一个基于对象的程序，在类中用带参数的构造函数对数据成员初始化。
#include<iostream>
using namespace std;
class Box                      //声明Box类
  {public:
     Box(int,int,int);         //声明带参数的构造函数
     int volume();             //声明计算体积的函数
   private:
     int height;               //高
     int width;                //宽
     int length;               //长
  };
Box::Box(int h,int w,int len)  //在类外定义带参数的构造函数
  {height=h;
   width=w;
   length=len;
  }

int Box::volume()              //定义计算体积的函数
  {return(height*width*length);
  }

int main()
  {Box box1(12,25,30);         //建立对象box1,并指定box1的高、宽、长的值
   cout<<"The volume of box1 is "<<box1.volume()<<endl;
   Box box2(15,30,21);         //建立对象box2,并指定box2的高、宽、长的值
   cout<<"The volume of box2 is "<<box2.volume()<<endl;
   return 0;
  }