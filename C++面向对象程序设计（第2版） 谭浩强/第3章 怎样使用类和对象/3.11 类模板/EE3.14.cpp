//声明一个类模板，利用它分别实现两个整数、浮点娄和字符的比较，求出大数和小数。
#include<iostream>
using namespace std;
template<class numtype>              //声明类模板,虚拟类型名为numtype
class Compare                        //类模板名为Compare
  {public:
     Compare(numtype a,numtype b)    //定义构造函数
       {x=a;y=b;}
     numtype max()                   //函数类型暂定为numtype
       {return(x>y)?x:y;}
     numtype min()
       {return(x<y)?x:y;}
   private:
     numtype x,y;                    //数据类型暂定为numtype
  };

int main()
  {Compare<int> cmp1(3,7);           //定义对象cmp1,用于两个整数的比较
   cout<<cmp1.max()<<" is the Maximum of two integer numbers."<<endl;
   cout<<cmp1.min()<<" is the Minimum of two integer numbers."<<endl<<endl;
   Compare<float> cmp2(45.78,93.6);  //定义对象cmp2,用于两个浮点数的比较
   cout<<cmp2.max()<<" is the Maximum of two float numbers."<<endl;
   cout<<cmp2.min()<<" is the Minimum of two float numbers."<<endl<<endl;
   Compare<char> cmp3('a','A');      //定义对象cmp3,用于两个字符的比较
   cout<<cmp3.max()<<" is the Maximum of two characters."<<endl;
   cout<<cmp3.min()<<" is the Minimum of two characters."<<endl;
   return 0;
  }