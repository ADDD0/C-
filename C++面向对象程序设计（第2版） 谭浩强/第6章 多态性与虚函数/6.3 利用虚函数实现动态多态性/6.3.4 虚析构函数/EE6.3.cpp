//基类中有非虚析构函数时的执行情况。
#include<iostream>
using namespace std;
class Point                //定义基类Point类
  {public:
     Point(){}             //Point类构造函数
     ~Point(){cout<<"executing Point destructor"<<endl;}    //Point类析构函数
  };

class Circle:public Point  //定义派生类Circle类
  {public:
     Circle(){}            //Circle类构造函数
     ~Circle(){cout<<"executing Circle destructor"<<endl;}  //Circle类析构函数
  };

int main()
  { Point *p=new Circle;   //用new开辟动态存储空间
    delete p;              //用delete释放动态存储空间
    return 0;
  }