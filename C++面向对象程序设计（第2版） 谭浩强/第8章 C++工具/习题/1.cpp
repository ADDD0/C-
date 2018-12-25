/**
 * 求一元二次方程式ax²+bx+c=0的实根，如果方程没有实根，则输出有关警告信息。
 */
#include <iostream>

using namespace std;

int main() {
    float a, b, c, disc;

    cout << "a,b,c:";
    cin >> a >> b >> c;
    disc = b * b - 4 * a * c;
    if (disc < 0)
        cerr << "equation has no real root" << endl;
    else {
        cout << "x1=" << (disc - b) / (2 * a) << endl;
        cout << "x2=" << (-disc - b) / (2 * a) << endl;
    }
    return 0;
}