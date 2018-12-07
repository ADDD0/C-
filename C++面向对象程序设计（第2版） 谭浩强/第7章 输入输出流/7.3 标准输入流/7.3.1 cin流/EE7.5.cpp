//先后向变量grade输入若干个考试成绩，并对成绩在85分以上者
//输出信息“GOOD！”，小于60分者输出“FAIL！”。
//要求在输入时通过测试cin的真值，判断流对象是否处于正常状态。
#include<iostream>
using namespace std;
int main()
  {float grade;
   cout<<"enter grade:";
   while(cin>>grade)  //如果能从cin流正常读取数据,cin的值为真,执行循环体
     {if(grade>=85) cout<<grade<<" GOOD!"<<endl;
      if(grade<60) cout<<grade<<" FAIL!"<<endl;
      else cout<<grade<<" OK!"<<endl;
      cout<<"enter grade:";
     }
   cout<<"The end."<<endl;
   return 0;
  }