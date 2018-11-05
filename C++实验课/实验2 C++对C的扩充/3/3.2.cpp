#include <iostream>

using namespace std;

void display(int &a, int &b) {
    if (a > b)
        cout << a << " " << b << endl;
    else
        cout << b << " " << a << endl;
}

int main() {
    int a, b;

    cin >> a >> b;
    display(a, b);
    return 0;
}