#include <iostream>
#include <string.h>

using namespace std;

const int maxn=255;

class Poly {
    private:
        float *coe;  // 保存系数的结构,数组下标为幂次
    public:
        Poly() {
            coe = new float[maxn];
            memset(coe, 0, sizeof(float) * maxn);
        }

        void set() {
            int power;
            float c;

            cout << "input (exp coe | -1 0 to exit):";
            cin >> power >> c;
            while (power != -1) {
                coe[power] = c;
                cout << "input (exp coe | -1 0 to exit):";
                cin >> power >> c;
            }
        }

        void set(int power, float c) {
            coe[power] = c;
        }

        void print() {
            for (int i=0; i < maxn; ++i) {
                if (coe[i] == 0)
                    continue;
                cout << coe[i] << "x^" << i << " ";
            }
        }

        Poly operator +(Poly &p) {
            Poly result;
            for (int i=0; i < maxn; ++i)
                result.coe[i] = coe[i] + p.coe[i];
            return result;
        }

        Poly operator -(Poly &p) {
            Poly result;
            for (int i=0; i < maxn; ++i)
                result.coe[i] = coe[i] - p.coe[i];
            return result;
        }

        Poly operator *(Poly &p) {
            Poly result;
            for (int i=0; i < maxn; ++i) {
                if (coe[i] == 0)
                    continue;
                for (int j=0; j < maxn; ++j)
                    result.coe[j+i] += p.coe[j] * coe[i];
            }
            return result;
        }

        Poly operator /(Poly &p) {
            Poly result, tpdiv, tpc;
            Poly temp;
            int i, d, div;  // 除数与被除数
            float tc;

            tpdiv = *this;
            div = tpdiv.maxPowerCoe();
            d = p.maxPowerCoe();
            while ((i = (div - d)) >= 0) {
                tc = tpdiv.coe[div] / p.coe[d];
                result.coe[i] = tc;
                tpc.set(i, tc);
                temp = tpc * p;
                tpdiv = tpdiv - temp;
                tpc.set(i, 0);
                div = tpdiv.maxPowerCoe();
            }
            return result;
        }

        int maxPowerCoe() {
            int i;
            for (i = maxn - 1; i >= 0; --i)
                if (coe[i] == 0)
                    continue;
                else
                    break;
            return i;
        }
};

int main() {
    Poly a, b, c, d;
    Poly temp;

    cout << "input a:" << endl;
    a.set();
    cout << "input b:" << endl;
    b.set();

    cout << endl << "a=";
    a.print();
    cout << endl << "b=";
    b.print();
    c = a + b;
    cout << endl << "a+b=";
    c.print();
    c = a - b;
    cout << endl << "a-b=";
    c.print();
    c = a * b;
    cout << endl << "a*b=";
    c.print();
    c = a / b;
    cout << endl << "a/b=";
    c.print();
    temp = b * c;
    d = a - temp;
    cout << "...";
    d.print();
    cout << endl;

    return 0;
}