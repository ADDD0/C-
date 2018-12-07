//有5个学生的数据，要求：
//（1）把它们存到磁盘文件中；
//（2）将磁盘文件中的第1，3，5个学生数据读入程序，并显示出来；
//（3）将第3个学生的数据修改后存回磁盘文件中的原有位置；
//（4）从磁盘文件读入修改后的5个学生的数据并显示出来。
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student
  {int num;
   char name[20];
   float score;
  };
int main()
  {student stud[5]={1001,"Li",85,1002,"Fan",97.5,1004,"Wang",54,1006,
                   "Tan",76.5,1010,"Ling",96};
   fstream iofile("stud.dat",ios::in|ios::out|ios::binary);
   //用fstream类定义输入输出二进制文件流对象iofile
   if(!iofile)
   {cerr<<"open error!"<<endl;
    abort();
   }
   for(int i=0;i<5;i++)                          //向磁盘文件输出5个学生的数据
     iofile.write((char *)&stud[i],sizeof(stud[i]));
   student stud1[5];                             //用来存放从磁盘文件读入的数据
   for(int i=0;i<5;i=i+2)
     {iofile.seekg(i*sizeof(stud[i]),ios::beg);  //定位于第0,2,4学生数据开头
      iofile.read((char *)&stud1[i/2],sizeof(stud1[0]));
      //先后读入3个学生的数据,存放在stud1[0],stud[1]和stud[2]中
      cout<<stud1[i/2].num<<" "<<stud1[i/2].name<<" "<<stud1[i/2].score<<endl;
      //输出stud1[0],stud[1]和stud[2]各成员的值
     }
   cout<<endl;
   stud[2].num=1012;                             //修改第3个学生(序号为2)的数据
   strcpy(stud[2].name,"Wu");
   stud[2].score=60;
   iofile.seekp(2*sizeof(stud[0]),ios::beg);     //定位于经3个学生数据的开头
   iofile.write((char *)&stud[2],sizeof(stud[2]));    //更新第3个学生数据
   iofile.seekg(0,ios::beg);                          //重新定位于文件开头
   for(int i=0;i<5;i++)
     {iofile.read((char *)&stud[i],sizeof(stud[i]));  //读入5个学生的数据
      cout<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score<<endl;
     }
   iofile.close();
   return 0;
  }