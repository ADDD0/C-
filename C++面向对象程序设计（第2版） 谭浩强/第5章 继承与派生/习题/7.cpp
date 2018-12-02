/**
 * 有以下程序，请完成下面工作：
 * （1）阅读程序，写出运行时输出的结果。
 * （2）然后上机运行，验证结果是否正确。
 * （3）分析程序执行过程，尤其是调用构造函数的过程。
 * #include<iostream>
 * using namespace std;
 * class A
 *   {public:
 *      A(){a=0;b=0;}
 *      A(int i){a=i;b=0;}
 *      A(int i,int j){a=i;b=j;}
 *      void display(){cout<<"a="<<a<<"b="<<b;}
 *    private:
 *      int a;
 *      int b;
 *   };
 *
 * class B:public A
 *   {public:
 *      B(){c=0;}
 *      B(int i):A(i){c=0;}
 *      B(int i,int j):A(i,j){c=0;}
 *      B(int i,int j,int k):A(i,j){c=k;}
 *      void display1()
 *      {display();
 *       cout<<"c="<<c<<endl;
 *      }
 *    private:
 *      int c;
 *   };
 *
 * int main()
 *   {B b1;
 *    B b2(1);
 *    B b3(1,3);
 *    B b4(1,3,5);
 *    b1.display1();
 *    b2.display1();
 *    b3.display1();
 *    b4.display1();
 *    return 0;
 *   }
 */
