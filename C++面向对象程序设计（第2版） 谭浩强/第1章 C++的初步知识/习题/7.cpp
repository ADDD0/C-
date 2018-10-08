/**
 * 求2个或3个正整数中的最大数，用带有默认参数的函数实现。
 */
#include <iostream>

using namespace std;

int main() {
    unsigned a, b, c, maxf(unsigned, unsigned, unsigned);

    cin >> a >> b;
    if (cin.get() == '\n')
        cout << "max=" << maxf(a, b, c=0) << endl;
    else {
        cin >> c;
        cout << "max=" << maxf(a, b, c) << endl;
    }
    return 0;
}

unsigned maxf(unsigned x, unsigned y, unsigned z) {
    x = x < y ? y : x;
    x = x < z ? z : x;
    return x;
}