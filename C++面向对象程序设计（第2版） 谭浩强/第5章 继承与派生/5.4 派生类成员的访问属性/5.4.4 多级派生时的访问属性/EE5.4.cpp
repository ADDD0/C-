//多级派生的访问属性。
class A              //基类
  {public:
     int i;
   protected:
     void f1();
     int j;
   private:
     int k;
  };

class B:public A     //public派生类
  {public:
     void f2();
   protected:
     void f3();
   private:
     int m;
  };

class C:protected B  //protected派生类
  {public:
     void f4();
   private:
     int n;
  };