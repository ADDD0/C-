/**
 * 输入以下程序，进行编译，观察编译情况，如果有错误，请修改程序，再进行编译，
 * 直到没有错误，然后进行连接和运行，分析运行结果
 * （本题是《C++面向对象程序设计》第1章习题第9题）。
 *
 * #include<iostream>
 * using namespace std;
 * int main()
 * {
 *   int a,b;
 *   c=add(a,b)
 *   cout<<"a+b="<<c<<endl;
 *   return 0;
 * }
 * int add(int x,int y);
 * {
 *   z=x+y;
 *   return(z);
 * }
 */
#include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}

int main() {
    int a, b;

    cin >> a >> b;
    cout << "a+b=" << add(a, b) << endl;
    return 0;
}