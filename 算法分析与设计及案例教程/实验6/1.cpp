/**
 * ʹ�ö�̬�滮�����Դ���䣺����4����Դ�����3����Ŀ��ÿ����Ŀ��Ӧ���������£�
 * ʹ�����������ķ��䷽����
 */
#include <iostream>

using namespace std;

const int RESOURCE = 4; //��Դ����
const int CASE_NUM = 3; //��Ŀ����
//������Ŀ��ӦͶ������������
const double RATE[CASE_NUM][RESOURCE+1] = {{0, 0.23, 0.35, 0.36, 0.49},
                                         {0, 0.22, 0.36, 0.39, 0.54},
                                         {0, 0.38, 0.45, 0.9, 0.45}};
//����ǰi����Ŀ�Ķ���ÿ����Դ��������������(������һά�������,����Ϊdebug����)                                         
double array[100][100] = {0};

int main(){
    //��ʼ����һ����Ŀ�ĸ���Ͷ�������������
    for(int i = 0; i <= RESOURCE; i++){
        array [0][i] =  i*RATE[0][i];
    }

    int all = 0;    //allΪĿǰ�Ѿ�Ͷ�ʵ���Դ��
    for(int i = 1; i < CASE_NUM; i++){ //��ÿ����Ŀ��Ͷ����
        int y = 0; //��i - 1 ��ĿҪͶ�ʵ���Դ
        for(int j = 0; j <= RESOURCE; j++){ ////��ǰi����Ŀ�ܹ��������Դ����ĿͶ���� 0��RESOURCE
            double maxx = 0;    //��ǰͶ���������ӯ��
            for(int k = 0; k <= j; k++){    //����i��Ͷ��k����Դ�� k < = RESOURCE
                double temp = array[i - 1][j - k] + k * RATE[i][k];
                if(temp >= maxx){
                    maxx = temp;
                    y = j - k;
                }
            }
            array[i][j] = maxx;
        }
        all += y;
        printf("%d ��CASEͶ�� %d��\n", i, y);
    }
    printf("%d ��CASEͶ�� %d��\n", CASE_NUM, RESOURCE - all);
}