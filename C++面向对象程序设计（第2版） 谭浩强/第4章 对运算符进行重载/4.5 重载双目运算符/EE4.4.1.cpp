//声明一个字符串类String，用来存放不定长的字符串，重载运算符“==”，“<”和“>”，
//使他们能用于两个字符串的等于、小于和大于的比较运算。
#include<iostream>
using namespace std;
class String
  {public:
     String(){p=NULL;}                       //定义默认构造函数
     String(char *str);                      //声明构造函数
     void display();
   private:
     char *p;                                //字符型指针,用于指向字符串
  };
String::String(char *str)                    //定义构造函数
  {p=str;}                                   //使p指向实参字符串

void String::display()                       //输出p所指向的字符串
  {cout<<p;}

int main()
  {String string1("Hello"),string2("Book");  //定义对象
   string1.display();                        //调用公用成员函数
   cout<<endl;                               //换行
   string2.display();                        //调用公用成员函数
   return 0;
  }