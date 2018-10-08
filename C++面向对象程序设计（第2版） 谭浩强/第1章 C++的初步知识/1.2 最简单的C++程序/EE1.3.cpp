//从键盘输入两个数a和b，求两数中的大者。
#include<iostream>
using namespace std;
int main()
{ int max(int x,int y);  //对max函数作声明
  int a,b,c;
  cin>>a>>b;
  c=max(a,b);            //调用max函数
  cout<<"max="<<c<<endl;
  return 0;
}

int max(int x,int y)     //定义max函数
{ int z;
  if(x>y)z=x;
  else z=y;
  return(z);
}