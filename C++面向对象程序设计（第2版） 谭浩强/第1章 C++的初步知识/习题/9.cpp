/**
 * 对3个变量按由小到大顺序排序，要求使用变量的引用。
 */
#include <iostream>

using namespace std;

int main() {
    int a[3], i, j;

    for (int i=0; i < 3; ++i)
        cin>>a[i];
    for (int i=0; i < 3; ++i)
        for (int j=0; j < 2 - i; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    for (int i=0; i < 3; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

void swap(int &a, int &b) {
    int temp;

    temp = a;
    a = b;
    b = temp;
}