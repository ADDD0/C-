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
}