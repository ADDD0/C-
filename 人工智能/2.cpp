#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

vector< list<int> > graph;
bool visited[100] = {0};

void bfs(int v) {
    list<int>::iterator it;
    queue<int> q;

    cout << v;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (it = graph[v].begin(); it != graph[v].end(); ++it)
            if (!visited[*it]) {
                cout << *it;
                q.push(*it);
                visited[*it] = true;
            }
    }
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
    cout << "result for bfs(0):" << endl;
    bfs(0);

    return 0;
}