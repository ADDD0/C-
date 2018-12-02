/**
 * 有以下程序结构，请分析访问权限。
 * class A           //A为基类
 *   {public:
 *      void f1();
 *      int i;
 *    protected:
 *      void f2();
 *      int j;
 *    private:
 *      int k;
 *   };
 *
 * class B:public A  //B为A的公用派生类
 *   {public:
 *      void f3();
 *    protected:
 *      int m;
 *    private:
 *      int n;
 *   };
 *
 * class C:public B  //C为B的公用派生类
 *   {public:
 *      void f4();
 *    private:
 *      int p;
 *   };
 *
 * int main()
 *   {A a1;          //a1是基类A的对象
 *    B b1;          //b1是派生类B的对象
 *    C c1;          //c1是派生类C的对象
 *   }
 * 请问：
 * （1）在main函数中能否用b1.i，b1.j和b1.k引用派生类B对象b1中基类A的成员？
 * （2）派生类B中的成员函数能否调用基类A中的成员函数f1和f2？
 * （3）派生类B中的成员函数能否引用基类A中的数据成员i，j，k？
 * （4）能否在main函数中用c1.i，c1.j，c1.k，c1.m，c1.n，c1.p引用基类A
 * 的成员i，j，k，派生类B的成员m，n，以及派生类C的成员p？
 * （5）能否在main函数中用c1.f1()，c1.f2()，c1.f3()和c1.f4()
 * 调用f1，f2，f3，f4成员函数？
 * （6）派生类C的成员函数f4能否调用基类A中的成员函数f1，f2
 * 和派生类中的成员函数f3?
 */