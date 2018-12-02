//声明派生类Circle
#include<iostream>
using namespace std;
class Point
  {public:
     Point(float x=0,float y=0);
     void setPoint(float,float);
     float getX() const {return x;}
     float getY() const {return y;}
     friend ostream & operator<<(ostream &,const Point &);
   protected:
     float x,y;
  };

Point::Point(float a,float b)
  {x=a;y=b;}

void Point::setPoint(float a,float b)
  {x=a;y=b;}

ostream &operator<<(ostream &output,const Point &p)
  {output<<"["<<p.x<<","<<p.y<<"]"<<endl;
   return output;
}

class Circle:public Point       //Circle是Point类的公用派生类
  {public:
     Circle(float x=0,float y=0,float r=0);                 //构造函数
     void setRadius(float);     //设置半径值的函数
     float getRadius() const;   //读取半径值的函数
     float area() const;        //计算圆面积的函数
     friend ostream &operator<<(ostream &,const Circle &);  //重载运算符"<<"
   protected:
     float radius;
  };

//定义Circle类的构造函数,对圆心坐标和半径初始化
Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}
//定义设置半径值的函数
void Circle::setRadius(float r)
  {radius=r;}
//定义读取半径值的函数
float Circle::getRadius() const {return radius;}
//定义计算圆面积的函数
float Circle::area() const
  {return 3.14159*radius*radius;}
//重载运算符<<,使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output,const Circle &c)
  {output<<"Center=["<<c.x<<","<<c.y<<"],r="<<c.radius<<",area="
   <<c.area()<<endl;
   return output;
  }

int main()
  {Circle c(3.5,6.4,5.2);       //建立Circle类对象c并指定圆心坐标和半径
   cout<<"original circle:\nx="<<c.getX()<<",y="<<c.getY()<<",r="
   <<c.getRadius()<<",area="<<c.area()<<endl;  //输出圆心坐标、半径和面积
   c.setRadius(7.5);            //设置半径值
   c.setPoint(5,5);             //设置圆心坐标值x,y
   cout<<"new circle:\n"<<c;    //用重载运算符<<输出圆对象的信息
   Point &pRef=c;               //pRef是Point类的引用,被c初始化
   cout<<"pRef:"<<pRef;         //输出pRef的信息
   return 0;
  }