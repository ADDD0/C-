//将一个对象的值赋给另一个对象。
#include<iostream>
using namespace std;
class Box
  {public:
     Box(int=10,int=10,int=10);  //声明有默认参数的构造函数
     int volumn();
   private:
     int height;
     int width;
     int length;
  };

Box::Box(int h,int w,int len)    //定义构造函数
  {height=h;
   width=w;
   length=len;
  }

int Box::volumn()                //定义volumn函数
  {return(height*width*length);  //返回体积
  }

int main()
  {Box box1(15,30,25),box2;      //定义两个对象box1和box2
   cout<<"The volumn of box1 is "<<box1.volumn()<<endl;
   box2=box1;                    //将box1的值赋给box2
   cout<<"The volumn of box2 is "<<box2.volumn()<<endl;
   return 0;
  }