#include <iostream>

using namespace std;

unsigned maxf(unsigned x, unsigned y, unsigned z) {
    x = x < y ? y : x;
    x = x < z ? z : x;
    return x;
}

int main() {
    unsigned a, b, c;

    cin >> a >> b;
    if (cin.get() != '\n')  // 也有小bug
        cin >> c;
    cout << "max=" << maxf(a, b, c) << endl;
    return 0;
}