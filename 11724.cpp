#include <iostream>
#include <vector>
using namespace std;
vector<int> g[1001];
bool check[1001];
void dfs (int x) {
    check[x] = true;
    for (int i = 0; i < g[x].size(); i++) {
        int next = g[x][i];
        if (!check[next]) {
            dfs(next);
        }
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
