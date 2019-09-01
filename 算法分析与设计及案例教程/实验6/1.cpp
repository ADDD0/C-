/**
 * 使用动态规划解决资源分配问题
 */
#include <iostream>

using namespace std;

const int RESOURCE = 4; //资源数量
const int CASE_NUM = 3; //项目数量
//各个项目对应投资量的收益率
const double RATE[CASE_NUM][RESOURCE+1] = {{0, 0.23, 0.35, 0.36, 0.49},
                                         {0, 0.22, 0.36, 0.39, 0.54},
                                         {0, 0.38, 0.45, 0.9, 0.45}};
//保存前i个项目的对于每个资源的最大收益的数组(可以用一维数组代替,这里为debug方便)
double array[100][100] = {0};

int main(){
    //初始化第一个项目的各个投资数的最佳收益
    for(int i=0; i <= RESOURCE; ++i)
        array [0][i] =  i*RATE[0][i];

    int all = 0;                         //all为目前已经投资的资源数
    for(int i=1; i < CASE_NUM; ++i) {    //求每个项目的投资数
        int y=0;                         //第i-1项目要投资的资源
        //给前i个项目总共分配的资源,项目投资数0~RESOURCE
        for(int j=0; j <= RESOURCE; ++j) {
            double maxx=0;               //当前投资数下最大盈利
            for(int k=0; k <= j; ++k) {  //给第i个投资k个资源,k<=RESOURCE
                double temp = array[i - 1][j - k] + k * RATE[i][k];
                if(temp > maxx){
                    maxx = temp;
                    y = j - k;
                }
            }
            array[i][j] = maxx;
        }
        all += y;
        cout << i << "号CASE投资 %d" << y << " 个" << endl;
    }
    cout << CASE_NUM << "号CASE投资 %d" << RESOURCE - all << " 个" << endl;
}