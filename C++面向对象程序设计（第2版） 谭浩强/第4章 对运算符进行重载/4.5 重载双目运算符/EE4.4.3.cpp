#include<iostream>
#include<cstring>
using namespace std;
class String
  {public:
     String(){p=NULL;}
     String(char *str);
     friend bool operator>(String &string1,String &string2);
     friend bool operator<(String &string1,String &string2);
     friend bool operator==(String &string1,String &string2);
     void display();
   private:
     char *p;
  };
String::String(char *str)
  {p=str;}

void String::display()
  {cout<<p;}

bool operator>(String &string1,String &string2)   //对运算符">"重载
  {if(strcmp(string1.p,string2.p)>0)
     return true;
   else
     return false;
  }

bool operator<(String &string1,String &string2)   //对运算符"<"重载
  {if(strcmp(string1.p,string2.p)<0)
     return true;
   else
     return false;
  }

bool operator==(String &string1,String &string2)  //对运算符"=="重载
  {if(strcmp(string1.p,string2.p)==0)
     return true;
   else
     return false;
  }
int main()
  {String string1("Hello"),string2("Book"),string3("Computer");
   cout<<(string1>string2)<<endl;                 //比较结果应该为true(即1)
   cout<<(string1<string3)<<endl;                 //比较结果应该为false(即0)
   cout<<(string1==string2)<<endl;                //比较结果应该为false(即0)
   return 0;
  }