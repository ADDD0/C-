//输出立方体的体积，使用静态数据成员。
#include<iostream>
using namespace std;
class Box
  {public:
     Box(int,int);
     int volumn();
     static int height;      //把height定义为公用的静态的数据成员
     int width;
     int length;
  };
Box::Box(int w,int len)      //通过构造函数对width和length赋初值
  {width=w;
   length=len;
  }
int Box::volumn()            //定义成员函数volume
  {return(height*width*length);
  }
int Box::height=10;          //对静态数据成员height初始化

int main()
  {
   Box a(15,20),b(20,30);    //建立两个对象
   cout<<a.height<<endl;     //通过对象名a引用静态数据成员
   cout<<b.height<<endl;     //通过对象名b引用静态数据成员
   cout<<Box::height<<endl;  //通过类名引用静态数据成员
   cout<<a.volumn()<<endl;   //调用volumn函数,计算体积,输出结果
   return 0;
  }