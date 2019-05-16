#include <iostream>

using namespace std;

int main() {
    int box[] = {90, 100, 90, 100, 90, 100, 90, 100, 90, 100};
    int total=0;
    int standard=0;
    int num=1;

    for (int i=0; i < 10; ++i, num *= 2) {
        total += num * box[i];
        standard += num * 100;
    }

    int difference = (standard - total) / 10;
    while (difference)
        for (int defective=1, num=1; defective < 11; ++defective, num *= 2)
            if (num * 2 > difference) {
                difference -= num;
                cout << defective << ' ';
                break;
            }
    cout << "is defective" << endl;

    return 0;
}