#include <queue>
#include <tuple>
#include <cstdio>
#include <cstring>
using namespace std;
int d[1001][1001];
int n;
void bfs (int s, int c) {
    queue<pair<int, int>> q;
    q.push(make_pair(s, c));
    while (!q.empty()) {
        tie(s, c) = q.front(); 
        q.pop();
        if (d[s][s] == -1) {
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s, s));
        }
        if (s + c <= n && d[s + c][c] == -1) {
            d[s + c][c] = d[s][c] + 1;
            q.push(make_pair(s + c, c));
        }
        if (s - 1 >= 0 && d[s - 1][c] == -1) {
            d[s - 1][c] = d[s][c] + 1;
            q.push(make_pair(s - 1, c));
        }
    }
}
int main () {
    scanf("%d", &n);
    memset(d, -1, sizeof(d));
    d[1][0] = 0;
    bfs(1, 0);
    int ans = -1;
    for (int i = 0; i <= n; i++) {
        if (d[n][i] != -1){
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}