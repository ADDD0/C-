//有一个字符串“BASIC”，要求把它们按相反的顺序输出。
#include<iostream>
using namespace std;
int main()
  {char *p="BASIC";     //字符指针指向'B'
   for(int i=4;i>=0;i--)
     cout.put(*(p+i));  //从最后一个字符开始输出
   cout.put('\n');
   return 0;
  }