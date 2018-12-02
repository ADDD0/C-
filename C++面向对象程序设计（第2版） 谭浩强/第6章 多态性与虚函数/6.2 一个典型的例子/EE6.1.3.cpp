//声明Circle的派生类Cylinder
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

class Circle:public Point
  {public:
     Circle(float x=0,float y=0,float r=0);
     void setRadius(float);
     float getRadius() const;
     float area() const;
     friend ostream &operator<<(ostream &,const Circle &);
   protected:
     float radius;
  };

Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}

void Circle::setRadius(float r)
  {radius=r;}

float Circle::getRadius() const {return radius;}

float Circle::area() const
  {return 3.14159*radius*radius;}

ostream &operator<<(ostream &output,const Circle &c)
  {output<<"Center=["<<c.x<<","<<c.y<<"],r="<<c.radius<<",area="
   <<c.area()<<endl;
   return output;
  }

class Cylinder:public Circle               //Cylinder是Circle的公用派生类
  {public:
     Cylinder(float x=0,float y=0,float r=0,float h=0);     //构造函数
     void setHeight(float);                //设置圆柱高的函数
     float getHeight() const;              //读取圆柱高的函数
     float area() const;                   //计算圆表面积的函数
     float volume() const;                 //计算圆柱体积的函数
     friend ostream& operator<<(ostream&,const Cylinder&);  //重载运算符"<<"
   protected:
     float height;                         //圆柱高
  };
//定义构造函数
Cylinder::Cylinder(float a,float b,float r,float h)
  :Circle(a,b,r),height(h){}
//定义设置圆柱高的函数
void Cylinder::setHeight(float h){height=h;}
//定义读取圆柱高的函数
float Cylinder::getHeight() const {return height;}
//定义计算圆柱表面积的函数
float Cylinder::area() const
  { return 2*Circle::area()+2*3.14159*radius*height;}
//定义计算圆柱体积的函数
float Cylinder::volume() const
  {return Circle::area()*height;}
//重载运算符"<<"的函数
ostream &operator << (ostream &output,const Cylinder& cy)
  {output<<"Center=["<<cy.x<<","<<cy.y<<"],r="<<cy.radius<<",h="
   <<cy.height<<"\narea="<<cy.area()<<",volume="<<cy.volume()<<
   endl;
   return output;
}

int main()
  {Cylinder cy1(3.5,6.4,5.2,10);           //定义Cylinder类对象cy1,并初始化
   cout <<"original cylinder:\nx="<<cy1.getX()<<",y="<<cy1.getY()<<",r="
        <<cy1.getRadius()<<",h="<<cy1.getHeight()<<"\narea="<<cy1.area()
        <<",volume="<<cy1.volume()<<endl;  //用系统定义的运算符"<<"输出圆柱
                                           //cy1的数据
   cy1.setHeight(15);                      //设置圆柱高
   cy1.setRadius(7.5);                     //设置圆半径
   cy1.setPoint(5,5);                      //设置圆心坐标值x,y
   cout<<"\nnew cylinder:\n"<<cy1;         //用重载运算符"<<"输出cy1的数据
   Point &pRef=cy1;                        //pRef是Point类对象的引用
   cout<<"\npRef as a point:"<<pRef;       //pRef作为一个"点"输出
   Circle &cRef=cy1;                       //cRef是Circle类对象的引用
   cout<<"\ncRef as a Circle:"<<cRef;      //cRef作为一个"圆"输出
   return 0;
  }