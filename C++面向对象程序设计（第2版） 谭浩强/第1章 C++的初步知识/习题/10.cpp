/**
 * 编一个程序，将两个字符串连接起来，结果取代第一个字符串。要求用string方法。
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;

    cin >> s1 >> s2;
    s1 += s2;
    cout << s1 << endl;
    return 0;
}