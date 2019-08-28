/*
 * 字符串的模式匹配算法:KMP算法
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string T) {
    vector<int> next(T.size(), 0);
    next[0] = -1;
    int k=0;
    for (int j=2; j < T.size(); ++j) {
        while (k > 0 && T[j-1] != T[k])
            k = next[k];
        if (T[j-1] == T[k])
            k++;
        next[j] = k;
    }
    return next;
}

int KMP(string S, string T) {
    vector<int> next = getNext(T);
    int i=0, j=0;
    while (S[i] != '\0' && T[j] != '\0') {
        if (S[i++] == T[j++])
            ;
        else
            j = next[j];
        if (j == -1) {
            ++i;
            ++j;
        }
    }
    if (T[j] == '\0')
        return i - j;
    else
        return -1;
}

int main() {
    string S = "ababaababcb";
    string T = "ababc";
    int num = KMP(S, T);
    cout << num << endl;
    return 0;
}