//计算和输出3个立方体的体积。
#include<iostream>
using namespace std;
class Box
  {public:
     Box(int h=10,int w=12,int len=15):height(h),width(w),length(len){}
     //声明有默认参数的构造函数,用参数初始化表对数据成员初始化
     int volume();
   private:
     int height;
     int width;
     int length;
  };

int Box::volume()
  {return(height*width*length);
  }

int main()
  {Box a[3] = {       //定义对象数组
      Box(10,12,15),  //调用构造函数Box,提供第1个元素的实参
      Box(15,18,20),  //调用构造函数Box,提供第2个元素的实参
      Box(16,20,26)   //调用构造函数Box,提供第3个元素的实参
     };
   cout<<"volume of a[0] is "<<a[0].volume()<<endl;  //调用a[0]的volume函数
   cout<<"volume of a[1] is "<<a[1].volume()<<endl;  //调用a[1]的volume函数
   cout<<"volume of a[2] is "<<a[2].volume()<<endl;  //调用a[2]的volume函数
   return 0;
  }