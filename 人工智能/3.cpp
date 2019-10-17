#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

vector< list<int> > graph;
bool visited[100] = {0};

void dfs(int v) {
    list<int>::iterator it;
    visited[v] = true;
	cout << v;
    for (it = graph[v].begin(); it != graph[v].end(); ++it)
		if (!visited[*it])
             dfs(*it);
	cout << endl;
}

int main() {
    int n;
    cout << "input node num:";
    cin >> n;

    cout << "input data from 0, end with node num:" << endl;
    for (int i=0; i < n; ++i) {
        list<int> tl;
        int t;
        while (cin >> t && t != n)
            tl.push_back(t);
        graph.push_back(tl);
    }
    cout << "result for dfs(0):" << endl;
    dfs(0);

    return 0;
}