//名字冲突。
//main file
#include<iostream>
#include"header1.h"    //注意要用双引号,因为文件一般是放在用户目录中的
//#include"header1.h"  //包含头文件1
//#include"header2.h"  //包含头文件2
int main()
  {Student stud1(101,"Wang",18);  //定义类对象stud1
   stud1.get_data();
   cout<<fun(5,3)<<endl;
   return 0;
  }