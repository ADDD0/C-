/**
 * 在例7.17的基础上，修改程序，将存放在c数组中的数据读入并显示出来。
 */
#include <iostream>
#include <strstream>

using namespace std;

struct student {
    int num;
    char name[20];
    float score;
};

void show(student s) {
    cout << "num:" << s.num << endl;
    cout << "name:" << s.name << endl;
    cout << "score:" << s.score << endl << endl;
}

int main() {
    student stud[3]={1001, "Li", 78,
                     1002, "Wang", 89.5,
                     1004, "Fan", 90};
    char c[50];
    ostrstream strout(c, sizeof(c));
    istrstream strin(c, sizeof(c));

    for (int i=0; i < 3; ++i)
        strout << stud[i].num << " "
               << stud[i].name << " "
               << stud[i].score << " ";
    strout << ends;
    for (int i=0; i < 3; ++i) {
        strin >> stud[i].num >> stud[i].name >> stud[i].score;
        show(stud[i]);
    }
    return 0;
}