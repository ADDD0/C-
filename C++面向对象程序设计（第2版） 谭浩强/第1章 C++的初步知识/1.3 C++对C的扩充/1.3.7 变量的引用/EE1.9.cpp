//了解引用和变量的关系。
#include<iostream>
using namespace std;
int main()
{int a=10;
 int &b=a;  //声明b是a的引用
 a=a*a;     //a的值变化了,b的值也应一起变化
 cout<<a<<" "<<b<<endl;
 b=b/5;     //b的值变化了,a的值也应一起变化
 cout<<b<<" "<<a<<endl;
 return 0;
}