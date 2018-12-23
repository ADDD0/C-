/**
 * 编程序，在显示屏上显示一个由字母B组成的三角形。
 *                      B
 *                     BBB
 *                    BBBBB
 *                   BBBBBBB
 *                  BBBBBBBBB
 *                 BBBBBBBBBBB
 *                BBBBBBBBBBBBB
 *               BBBBBBBBBBBBBBB
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int height=8;

    for (int i=0; i < height; ++i) {
        cout << setfill(' ') << setw(height-i) << ' ';
        cout << setfill('B') << setw(2*i+1) << 'B';
        cout << endl;
    }
    return 0;
}
