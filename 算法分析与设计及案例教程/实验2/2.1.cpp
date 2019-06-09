/**
 * 有n箱产品,每箱1000件,正品每件100克,其中一箱是次品,
 * 次品每件比正品轻10g,能否称一次测出哪箱为次品?
 */
#include <iostream>

using namespace std;

int main() {
    int box[] = {100, 100, 100, 100, 100, 100, 90, 100, 100, 100};
    int total=0;
    int standard=0;

    for (int i=1; i < 11; ++i) {
        total += i * box[i-1];
        standard += i * 100;
    }

    int defective = (standard - total) / 10;
    cout << defective << " is defective" << endl;

    return 0;
}