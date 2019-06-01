/**
 * 币值最大化问题：问题描述：给定一排n个硬币，其面值均为正整数c1,c2,...,cn,
 * 这些整数不一定两两不同。请问如何选择硬币，使得其原始位置互不相邻的条件下，
 * 所选硬币的总金额最大。实例：硬币面值为：5，1，2，10，6，2
 */

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cout << "请输入硬币的总数（n）：";
	cin >> n;
	int *arr = (int *)malloc((n + 1) * sizeof(int));//分配空间，存储数据（可以当成数组）
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int *f = (int *)malloc((n + 1) * sizeof(int));//分配空间，存储数据（可以当成数组）
	f[0] = 0;
	f[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		f[i] = max(f[i - 2] + arr[i], f[i - 1]);//i个硬币时，最大金额f[i]=包括arr[i]与不包括arr[i]中的最大值
	}
	cout << "总金额最大为：";
	cout << f[n] << endl;
	cout << "分别是：" << endl;
	//通过回溯法，得到选择的硬币
	int *arr2 = (int *)malloc((n + 1) * sizeof(int));//分配空间，存储数据（可以当成数组）
	int num = 0;
	for (int i = n; i >= 1; i--)
	{
		if (f[i] == f[i - 1])//判断f[i]是否等于f[i-1]，若等于即没有选择arr[i]，反之则选择了
		{
			arr2[num++] = arr[--i];
		}
		else
		{
			arr2[num++] = arr[i--];
		}
	}
	sort(arr2, arr2 + num);
	for (int i = 0; i < num; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	return 0;
}