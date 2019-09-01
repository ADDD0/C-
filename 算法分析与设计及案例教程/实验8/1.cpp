/**
 * 对七巧板的每块进行编号,使用邻接矩阵存储该七巧板,两编号相邻记为1,反之记为0
 * 试设计算法,使用至多4种不同的颜色对七巧板进行涂色(每块涂一种颜色),
 * 要求相邻区域的颜色互不相同,打印输出所有可能的颜色
 */
#include <iostream>

using namespace std;

const int n=7;  //三角板个数

//邻接矩阵表,用来判断是否相邻
const int data[n][n] = {
    {0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 1, 1, 0, 0}
};

int color[n]= {0,0,0,0,0,0,0};  //每个三角板的颜色
static int total;
void tryFind(int s);   //查找涂色方案的递归
int colorSame(int s);  //判断与周围的三角板颜色是否相同
void output();         //输出涂色方案

int main() {
    total = 0;
    tryFind(0);
    cout << "Total=" << total << endl;
    return 0;
}

void tryFind(int s) {
    //s=0~6,如果s=7说明已经涂完
    if(s==n)
        output();
    else {
        //1,2,3,4代表四种颜色
        //只有与周围三角块的颜色不同时才会进入下一个三角板的涂色
        for (int i=1; i <= 4; ++i) {
            color[s] = i;
            if (colorSame(s) == 0)
                tryFind(s + 1);
        }
    }
}

int colorSame(int s) {
    int flag=0;
    for (int i=0; i < s; ++i)
        //使用邻接矩阵判断是否相邻,如果相邻判断颜色是否相同
        if (data[i][s] == 1 && color[i] == color[s])
            flag = 1;
    return flag;
}

void output() {
    cout << "serial number:";
    for (int i=0; i < n; ++i)
        cout << color[i] << " ";
    total++;
    cout << endl;
}