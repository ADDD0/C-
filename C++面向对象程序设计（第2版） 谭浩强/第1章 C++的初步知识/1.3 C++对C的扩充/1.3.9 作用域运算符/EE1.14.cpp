//局部变量和全局变量同名。
#include<iostream>
using namespace std;
float a=13.5;
int main()
{int a=5;
 cout<<a<<endl;    //输出局部变量a的值
 cout<<::a<<endl;  //输出全局变量a的值
 return 0;
}