//逐个读入一行字符，将其中的非空格字符输出。
#include<iostream>
using namespace std;
int main()
  {char c;
   while(!cin.eof())         //eof()为假表示未遇文件结束符
     if((c=cin.get())!=' ')  //检查读入的字符是否空格字符
       cout.put(c);
   return 0;
  }