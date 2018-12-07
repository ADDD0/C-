//有一元二次方程ax²+bx+c=0，其一般解为x1,2=(-b±√(4ac))/2a
//但若a=0，或b²-4ac<0时，用此公式出错，用cerr流输出有关信息。
//从键盘输入a，b，c的值，求x1和x2的值。如果a=0或b²-4ac<0则应输出出错信息。
#include<iostream>
#include<cmath>
using namespace std;
int main()
  {float a,b,c,disc;
   cout<<"please input a,b,c:";
   cin>>a>>b>>c;
   if(a==0)
     cerr<<"a is equal to zero,error!"<<endl;
     //将有关出错信息插入cerr流,在屏幕输出
   else
     if((disc=b*b-4*a*c)<0)
       cerr<<"disc=b*b-4*a*c<0"<<endl;
       //将有关出错信息插入cerr流,在屏幕输出
     else
       {cout<<"x1="<<(-b+sqrt(disc))/(2*a)<<endl;
        cout<<"x2="<<(-b-sqrt(disc))/(2*a)<<endl;
       }
   return 0;
  }