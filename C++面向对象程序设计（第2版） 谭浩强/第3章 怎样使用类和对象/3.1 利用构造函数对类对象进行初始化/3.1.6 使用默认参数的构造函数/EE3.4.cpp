//将例3.3程序中的构造函数改用含默认值的参数，宽、高、长的默认值均为10。
#include<iostream>
using namespace std;
class Box
  {public:
     Box(int h=10,int w=10,int len=10);  //在声明构造函数Box时指定默认参数
     int volume();
   private:
     int height;
     int width;
     int length;
  };
Box::Box(int h,int w,int len)            //在定义Box函数时可以不指定默认参数
  {height=h;
   width=w;
   length=len;
  }

int Box::volume()
  {return(height*width*length);
  }

int main()
  {
   Box box1;                             //没有给定实参
   cout<<"The volume of box1 is "<<box1.volume()<<endl;
   Box box2(15);                         //只给定一个实参
   cout<<"The volume of box2 is "<<box2.volume()<<endl;
   Box box3(15,30);                      //只给定两个实参
   cout<<"The volume of box3 is "<<box3.volume()<<endl;
   Box box4(15,30,20);                   //给定3个实参
   cout<<"The volume of box4 is "<<box4.volume()<<endl;
   return 0;
  }