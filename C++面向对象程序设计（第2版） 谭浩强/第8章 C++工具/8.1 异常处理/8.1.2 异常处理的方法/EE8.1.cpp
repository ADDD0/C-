//给三角形的三边a,b,c,求三角形的面积。只有a+b>c，b+c>a，c+a>b时才能
//构成三角形。设置异常处理，对不符合三角形条件的输出警告信息，不予计算。
#include<iostream>
#include<cmath>
using namespace std;
int main()
  {double triangle(double,double,double);
   double a,b,c;
   cin>>a>>b>>c;
   try                 //在try块中包括要检查的函数
     {while(a>0 && b>0 && c>0)
       {cout<<triangle(a,b,c)<<endl;
        cin>>a>>b>>c;
       }
     }
   catch(double)       //用catch捕捉异常信息并作相应处理
     {cout<<"a="<<a<<",b="<<b<<",c="<<c<<",that is not a triangle!"<<endl;
     }

   cout<<"end"<<endl;  //最后输出"end"
   return 0;           //返回0,程序正常结束
  }

double triangle(double a,double b,double c)  //定义计算三角形的面积的函数
  {double s=(a+b+c)/2;
   if(a+b<=c||b+c<=a||c+a<=b) throw a;       //当不符合三角形条件抛出异常信息a
   return sqrt(s*(s-a)*(s-b)*(s-c));
  }