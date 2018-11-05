/**
 * 含类定义的头文件student.h。
 *
 * //student.h                (这是头文件，在此文件中进行类的声明)
 * class Student              //类声明
 *       { public:
 *           void display();  //公用成员函数原型声明
 *         private:
 *           int num;
 *           char name[20];
 *           char sex;
 *       };
 */
class Student {
    public:
        void set_value();
        void display();
    private:
        int num;
        char name[20];
        char sex;
};