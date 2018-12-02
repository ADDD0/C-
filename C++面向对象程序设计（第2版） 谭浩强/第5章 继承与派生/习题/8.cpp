/**
 * 有以下程序，请完成下面工作：
 * （1）阅读程序，写出运行时输出的结果。
 * （2）然后上机运行，验证结果是否正确。
 * （3）分析程序执行过程，尤其是调用构造函数和析构函数的过程。
 * #include<iostream>
 * using namespace std;
 * class A
 *   {public:
 *    A(){cout<<"constructing A"<<endl;}
 *    ~A(){cout<<"destructing A"<<endl;}
 *   };
 *
 * class B:public A
 *   {public:
 *    B(){cout<<"constructing B"<<endl;}
 *    ~B(){cout<<"destructing B"<<endl;}
 *   };
 *
 * class C:public B
 *   {public:
 *    C(){cout<<"constructing C"<<endl;}
 *    ~C(){cout<<"destructing C"<<endl;}
 *   };
 * int main()
 *   {C c1;
 *    return 0;
 *   }
 */