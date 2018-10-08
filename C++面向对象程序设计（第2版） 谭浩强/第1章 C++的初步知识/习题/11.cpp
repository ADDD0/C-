/**
 * 输入一个字符串，把其中的字符按逆序输出。如输入LIGHT，输出THGIL。
 * 要求用string方法。
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;

    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}