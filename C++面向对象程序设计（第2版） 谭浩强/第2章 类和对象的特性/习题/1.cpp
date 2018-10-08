/**
 * 请检查下面程序，找出其中的错误（先不要上机，在纸面上作人工检查），并改正之。
 * 然后上机测试，使之能正常运行。运行时从键盘输入时、分、秒的值，检查输出是否正确。
 * #include<iostream>
 * using namespace std;
 * class Time
 * { void set_time(void);
 *   void show_time(void);
 *   int hour;
 *   int minute;
 *   int sec;
 * };
 * Time t;
 * int main()
 * {
 *   set_time();
 *   show_time();
 *   return 0;
 * }
 * int set_time()
 * {
 *   cin>>t.hour;
 *   cin>>t.minute;
 *   cin>>t.sec;
 * }
 * int show_time()
 * {
 *   cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
 * }
 */
#include <iostream>

using namespace std;

class Time {
    private:
        int hour;
        int minute;
        int sec;
    public:
        void set_time();
        void show_time();
};

int main() {
    Time t;

    t.set_time();
    t.show_time();
    return 0;
}

void Time::set_time() {
    cin >> hour >> minute >> sec;
}

void Time::show_time() {
    cout << hour << ":" << minute << ":" << sec << endl;
}