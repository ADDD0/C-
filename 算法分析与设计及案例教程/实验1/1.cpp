/**
 * 设计递归算法实现:从n个不同的任意数中,取出r个数的组合.
 * 要求:n、n个数及r均从键盘输入.
 */
#include <iostream>

using namespace std;

void comb(int a[], int res[], int n, int r, int LENGTH) {
    for (int i=n; i >= r; --i) {
        res[r-1] = a[i-1];
        if (r > 1)
            comb(a, res, i-1, r-1, LENGTH);
        else {
            for (int j=0; j < LENGTH; ++j)
                cout << res[j] << ' ';
            cout << endl;
        }
    }
}

int main() {
    int n, r;

    cin >> n >> r;

    int *a = new int[n];
    int *res = new int[n];

    for (int i=0; i < n; ++i)
        cin >> a[i];

    int const LENGTH=r;
    comb(a, res, n, r, LENGTH);

    return 0;
}