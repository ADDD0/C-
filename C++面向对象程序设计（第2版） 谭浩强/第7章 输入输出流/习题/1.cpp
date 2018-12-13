/**
 * 输入三角形的三边a，b，c，计算三角形的面积的公式是
 * area=sqrt(s(s-a)(s-b)(s-c))，s=(a+b+c)/2
 * 形成三角形的条件是：a+b>c，b+c>a，c+a>b
 * 编写程序，输入a，b，c，检查a，b，c是否满足以上条件，
 * 如不满足，由cerr输出有关出错信息。
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c, s, area;

    cout << "a,b,c:";
    cin >> a >> b >> c;
    if (a + b > c && b + c > a) {
        s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "area:" << area << endl;
    } else
        cerr << "input info error" << endl;
    return 0;
}