/**
 * 分析下面程序运行的结果。请先阅读程序写出程序运行时应输出的结果，然后上机运行
 * 程序，验证自己分析的结果是否正确。以下各题同。
 */
#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  int f(int x,int y,int z);
  cin>>a>>b>>c;
  c=f(a,b,c);
  cout<<c<<endl;
  return 0;
}
int f(int x,int y,int z)
{
  int m;
  if(x<y)m=x;
  else m=y;
  if(z<m)m=z;
  return(m);
}