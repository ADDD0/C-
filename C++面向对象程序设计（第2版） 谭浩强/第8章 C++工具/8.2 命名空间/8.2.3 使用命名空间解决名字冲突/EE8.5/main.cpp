//利用命名空间来解决例8.4程序名字冲突问题。
//main file(主文件)
#include<iostream>
#include"header1.h"                    //包含头文件1
#include"header2.h"                    //包含头文件2
int main()
  {ns1::Student stud1(101,"Wang",18);  //用命名空间ns1中的Student类定义stud1
   stud1.get_data();                   //不要写成ns1::stud1.get_data();
   cout<<ns1::fun(5,3)<<endl;          //调用命名空间ns1中的fun函数
   ns2::Student stud2(102,"Li",'f');   //用命名空间ns2中的Student类定义stud2
   stud2.get_data();
   cout<<ns2::fun(5,3)<<endl;          //调用命名空间ns2中的fun函数
   return 0;
  }