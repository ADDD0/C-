/**
 * 时间安排问题
 * 有n项工作,每项工作分别在Si开始,Ti结束.对每项工作,你都可以选择参加与否,
 * 若选择参加,则必须至始至终参加全程参与,且参与工作的时间段不能有重叠
 * 例如S={1,2,4,6,8},T={3,5,7,8,10}
 */
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define Max_N 1000

int main() {
    int n;
    pair<int,int> p[Max_N];

    cin >> n;
    for (int i=0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        p[i] = make_pair(end, start);
    }                //输入数据,并组成pair对保存在数组中
    sort(p, p + n);  //按照pair中第一个关键词进行升序排序

    int last=0, ans=0;
    cout << "选择的工作的起始时间有:" << endl;
    for(int i=0; i < n; ++i) {
        //现在寻找的下一个工作的开始时间大于上一次工作的结束时间,则选择该次工作
        if(p[i].second > last) {
            last = p[i].first;
            ans++;
            cout << p[i].second << "--" << p[i].first << endl;
        }
    }
    cout << "共选择了" << ans << "个工作" << endl;
    return 0;
}