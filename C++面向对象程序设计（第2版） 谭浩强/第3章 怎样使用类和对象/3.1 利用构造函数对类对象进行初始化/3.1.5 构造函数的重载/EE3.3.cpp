//在例3.2的基础上，定义两个构造函数，其中一个无参数，一个有参数。
#include<iostream>
using namespace std;
class Box
  {public:
     Box();             //声明一个无参的构造函数Box
     Box(int h,int w,int len):height(h),width(w),length(len){}
     //定义一个有参的构造函数,用参数的初始化表对数据成员初始化
     int volume();      //声明成员函数volume
   private:
     int height;
     int width;
     int length;
  };
Box::Box()              //在类外定义无参构造函数Box
  {height=10;
   width=10;
   length=10;
  }

int Box::volume()       //在类外定义成员函数volume
  {return(height*width*length);
  }

int main()
  {Box box1;            //建立对象box1,不指定实参
   cout<<"The volume of box1 is "<<box1.volume()<<endl;
   Box box2(15,30,25);  //建立对象box2,指定3个实参
   cout<<"The volume of box2 is "<<box2.volume()<<endl;
   return 0;
  }