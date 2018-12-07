//用get函数读入字符。
#include<iostream>
using namespace std;
int main()
  {int c;
   cout<<"enter a sentence:"<<endl;
   while((c=cin.get())!=EOF)
     cout.put(c);
   return 0;
  }