/* 输入两个整数，将它们按由大到小的顺序输出。要求使用变量的引用。 */
#include <iostream>
using namespace std;

int main()
{
    int a, b, &c = a, &d = b;

    cin>>a>>b;
    if (a > b)
        cout<<c<<" "<<d<<endl;
    else
        cout<<d<<" "<<c<<endl;
    return 0;
}