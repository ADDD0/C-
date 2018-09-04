/* 有5个字符串，要求对它们按由小到大顺序排列，用string方法。 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s[5], temp;
    int i, j;

    for (i = 0; i < 5; ++i)
        cin>>s[i];
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 4 - i; ++j)
            if (s[j] > s[j + 1])
                temp = s[j], s[j] = s[j + 1], s[j + 1] = temp;
    for (i = 0; i < 5; ++i)
        cout<<s[i]<<endl;
    return 0;
}