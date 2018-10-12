/**
 * 商店销售某一商品，商店每天公布统一的折扣（discount）。同时允许销售人员在
 * 销售时灵活掌握售价（price），在此基础上，对一次购10件以上者，还可以享受
 * 98折优待。现已知当天3个销货员销售情况为
 *   销货员号（num）  销货件数（quantity）  销货单价（price）
 *        101                   5                 23.5
 *        102                  12                 24.56
 *        103                 100                 21.5
 * 请编程序，计算出当日此商品的总销售款sum以及每件商品的平均售价。要求用静态
 * 数据成员和静态成员函数。
 *
 * 提示：将折扣discount，总销售款sum和商品销售总件数n，声明为静态数据成员，
 * 再定义静态成员函数average（求平均售价）和display（输出结果）。
 */
#include <iostream>

using namespace std;

class Product {
    public:
        Product(int n, int q, float p): num(n), quantity(q), price(p) {}
        void total();
        static float average();
        static void display();

        static float discount;
        static float rate;
        static float sum;
        static int n;
    private:
        int num;
        float quantity;
        float price;
};

float Product::discount = 1;
float Product::rate = 1;
float Product::sum = 0;
int Product::n = 0;

void Product::total() {
    n += quantity;
    rate = quantity > 10 ? 0.98 : 1;
    sum += quantity * price * discount * rate;
}

float Product::average() {
    return sum / n;
}

void Product::display() {
    cout << "sum:" << sum << endl;
    cout << "average:" << average() << endl;
}

int main() {
    Product sale[3] = {
        Product(101, 5, 23.5),
        Product(102, 12, 24.56),
        Product(103, 100, 21.5),
    };

    cout << "input the discount(0,1]:";
    cin >> Product::discount;
    if (Product::discount <= 0 || Product::discount > 1)
        return 1;
    for (int i=0; i < 3; ++i)
        sale[i].total();
    Product::display();
    return 0;
}