/**
 * 有以下使用类模板程序（这是《C++面向对象程序设计》第3章例3.14的程序）:
 * #include<iostream>
 * using namespace std;
 * template<class numtype>              //定义类模板
 * class Compare
 *   {public:
 *     Compare(numtype a, numtype b)
 *      {x=a;y=b;}
 *     numtype max()
 *      {return(x>y)?x:y;}
 *     numtype min()
 *      {return(x<y)?x:y;}
 *    private:
 *      numtype x, y;
 *   };
 *
 * int main()
 * {Compare<int>cmp1(3, 7);           //定义对象cmp1，用于两个整数的比较
 *  cout<<cmp1.max()<<" is the Maximum of two integer numbers."<<endl;
 *  cout<<cmp1.min()<<" is the Minimum of two integer numbers."<<endl<<endl;
 *  Compare<float>cmp2(45.78, 93.6);  //定义对象cmp2，用于两个浮点数的比较
 *  cout<<cmp2.max()<<" is the Maximum of two flaot numbers."<<endl;
 *  cout<<cmp2.min()<<" is the Minimum of two float numbers."<<endl<<endl;
 *  Compare<char>cmp3('a', 'A');      //定义对象cmp3，用于两个字符的比较
 *  cout<<cmp3.max()<<" is the Maximum of two characters."<<endl;
 *  cout<<cmp3.min()<<" is the Minimum of two characters."<<endl;
 *  return 0;
 * }
 * ①运行此程序，体会类模板的作用。
 * ②将它改写为在类模板外定义各成员函数。
 */
#include <iostream>

using namespace std;

template <class numtype>
class Compare
  {public:
     Compare(numtype a, numtype b): x(a), y(b) {}
     numtype max();
     numtype min();
   private:
     numtype x, y;
  };

template <class numtype>
numtype Compare <numtype>::max() {
    return x > y ? x : y;
}
template <class numtype>
numtype Compare <numtype>::min() {
    return x < y ? x : y;
}

int main()
  {Compare <int> cmp1(3,7);
   Compare <float> cmp2(45.78,93.6);
   Compare <char> cmp3('a','A');

   cout << cmp1.max() << " is the Maximum of two integer numbers." << endl;
   cout << cmp1.min() << " is the Minimum of two integer numbers." << endl;
   cout << endl;

   cout << cmp2.max() << " is the Maximum of two float numbers." << endl;
   cout << cmp2.min() << " is the Minimum of two float numbers." << endl;
   cout << endl;

   cout << cmp3.max() << " is the Maximum of two characters." << endl;
   cout << cmp3.min() << " is the Minimum of two characters." << endl;
   return 0;
  }