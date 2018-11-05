#include <iostream>

using namespace std;

int main() {
    const int N=3;
    int a[N], i, j;

    for (int i=0; i < N; ++i)
        cin >> a[i];
    for (int i=0; i < N; ++i)
        for (int j=0; j < N - 1 - i; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    for (int i=0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}

void swap(int &x, int &y) {  // 不声明也可运行?
    int temp;

    temp = x;
    x = y;
    x = temp;
}