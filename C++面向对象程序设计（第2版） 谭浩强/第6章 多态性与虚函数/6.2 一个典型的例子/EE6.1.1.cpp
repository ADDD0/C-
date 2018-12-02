//先建立一个Point（点）类，包含数据成员x，y（坐标点）。
//以它为基类，派生出一个Circle（圆）类，增加数据成员r（半径）。
//再以Circle类为直接基类，派生出一个Cylinder（圆柱体）类，再增加数据成员h（高）。
//要求编写程序，重载运算符“<<”和“>>”，使之能用于输出以上类对象。
//声明基类Point
#include<iostream>
using namespace std;
//声明类Point
class Point
  {public:
     Point(float x=0,float y=0);       //有默认参数的构造函数
     void setPoint(float,float);       //设置坐标值
     float getX() const {return x;}    //读x坐标,getX函数为常成员函数
     float getY() const {return y;}    //读y坐标,getY函数为常成员函数
     friend ostream & operator<<(ostream &,const Point &);  //友元重载运算符"<<"
   protected:                          //受保护成员
     float x,y;
  };

//下面定义Point类的成员函数

//定义Point类的构造函数
Point::Point(float a,float b)          //对x,y初始化
  {x=a;y=b;}
//设置x和y的坐标值
void Point::setPoint(float a,float b)  //对x,y赋以新值
  {x=a;y=b;}
//重载运算符<<,使之能输出点的坐标
ostream &operator<<(ostream &output,const Point &p)
  {output<<"["<<p.x<<","<<p.y<<"]"<<endl;
   return output;
}

int main()
  {Point p(3.5,6.4);                   //建立Point类对象p,对x,y初始化
   cout<<"x="<<p.getX()<<",y="<<p.getY()<<endl;  //输出p的坐标值x,y初始化
   p.setPoint(8.5,6.8);                //重新设置p的坐标值
   cout<<"p(new):"<<p<<endl;           //用重载运算符<<输出p点坐标
   return 0;
  }