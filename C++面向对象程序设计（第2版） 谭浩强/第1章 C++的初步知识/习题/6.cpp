/**
 * 输入以下程序，编译并运行，分析运行结果。
 */
#include<iostream>
using namespace std;
int main()
{void sort(int x,int y,int z);
 int x,y,z;
 cin>>x>>y>>z;
 sort(x,y,z);
 return 0;
}
void sort(int x,int y,int z)
{
 int temp;
 if(x>y){temp=x;x=y;y=temp;}  //{}内3个语句的作用是将x和y的值互换
 if(z<x)cout<<z<<','<<x<<','<<y<<endl;
   else if(z<y) cout<<x<<','<<z<<','<<y<<endl;
     else cout<<x<<','<<y<<','<<z<<endl;
}