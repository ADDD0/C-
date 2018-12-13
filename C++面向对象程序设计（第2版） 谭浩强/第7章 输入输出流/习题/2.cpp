/**
 * 从键盘输入一批数值，要求保留3位小数，在输出时上下行小数点对齐。
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int length=3;
    float n[length];

    for (int i=0; i < length; ++i) {
        cout << "input data " << i + 1 << ":";
        cin >> n[i];
    }
    for (int i=0; i < length; ++i) {
        cout << setiosflags(ios::right) << setprecision(3);
        cout << n[i] << endl;
    }
    return 0;
}