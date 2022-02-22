#include <iostream>
#include <vector>
using namespace std;
vector<int> g[20001];
int color[20001];
bool dfs (int x, int c) {
    color[x] = c;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (color[y] == 0) {
            if (dfs(y, 3 - c) == false) return false;
        }else {
            if (color[x] == color[y]) return false;
        }
    }
    return true;
}
int main () {
    int k;
    cin >> k;
    while (k--) {
        int v, e;
        cin >> v >> e;
        //배열 초기화
        for (int i = 1; i <= v; i++) {
            g[i].clear();
            color[i] = 0;
        }
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool flag = true;
        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                if (dfs (i, 1) == false){
                    flag = false;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}