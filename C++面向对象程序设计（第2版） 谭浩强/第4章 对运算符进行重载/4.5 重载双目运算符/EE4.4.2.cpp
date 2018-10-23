#include<iostream>
#include<cstring>
using namespace std;
class String
  {public:
     String(){p=NULL;}
     String(char *str);
     friend bool operator>(String &string1,String &string2);
                                                 //声明运算符函数为友元函数
     void display();
   private:
     char *p;                                    //字符型指针,用于指向字符串
  };
String::String(char *str)
  {p=str;}

void String::display()                           //输出p所指向的字符串
  {cout<<p;}

bool operator>(String &string1,String &string2)  //定义运算符重载函数
  {if(strcmp(string1.p,string2.p)>0)
     return true;
   else return false;
  }

int main()
  {String string1("Hello"),string2("Book");
   cout<<(string1>string2)<<endl;
  }