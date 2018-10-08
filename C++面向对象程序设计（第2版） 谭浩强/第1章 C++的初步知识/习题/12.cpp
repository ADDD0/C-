/**
 * 有5个字符串，要求对它们按由小到大顺序排列，用string方法。
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s[5], temp;

    for (int i=0; i < 5; ++i)
        cin >> s[i];
    for (int i=0; i < 5; ++i)
        for (int j=0; j < 4 - i; ++j)
            if (s[j] > s[j + 1])
                temp = s[j], s[j] = s[j + 1], s[j + 1] = temp;
    for (int i=0; i < 5; ++i)
        cout << s[i] << endl;
    return 0;
}