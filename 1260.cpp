#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> g[1001]; //인접리스트
bool check[1001];
void dfs (int x) {
    check[x] = true;
    cout << x << ' ';
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (!check[y]) dfs(y);
    }
}
void bfs (int x) {
    queue<int> q;
    memset(check, false, sizeof(check));
    check[x] = true;
    q.push(x);
    while (!q.empty()) {
        int n = q.front(); q.pop();
        cout << n << ' ';
        for (int i = 0; i < g[n].size(); i++) {
            int y = g[n][i];
            if (!check[y]) {
                check[y] = true;
                q.push(y);
            }
        }
    }
}
int main () {
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    //방문 할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은것을 먼저 방문하라는 문제의 조건 때문에 정렬을 함
    for (int i = 1; i <= n; i++) { 
        sort (g[i].begin(), g[i].end());
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    return 0;
}