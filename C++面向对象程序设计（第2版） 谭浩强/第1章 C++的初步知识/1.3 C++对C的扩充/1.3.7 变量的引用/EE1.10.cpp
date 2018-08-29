//无法实现两个变量的值互换的程序。
#include<iostream>
using namespace std;
void swap(int a,int b)
  {int temp;
   temp=a;
   a=b;
   b=temp;    //实现a和b的值互换
  }

int main()
  {int i=3,j=5;
   swap(i,j);
   cout<<i<<","<<j<<endl;
   return 0;  //i和j的值未互换
  }