//用一个函数求2个整数或3个整数中的最大者。
#include<iostream>
using namespace std;
int max(int a,int b,int c)  //求3个整数中的最大者
  {if(b>a) a=b;
   if(c>a) a=c;
   return a;
  }
int max(int a,int b)        //求两个整数中的最大者
  {if(a>b) return a;
   else return b;
  }

int main()
  {int a=7,b=-4,c=9;
   cout<<"max_3="<<max(a,b,c)<<endl;  //输出3个整数中的最大者
   cout<<"max_2="<<max(a,b)<<endl;    //输出两个整数中的最大者
  }