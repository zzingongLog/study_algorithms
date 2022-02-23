#include <cstdio>
#include <deque>
#include <tuple>
#include <cstring>
using namespace std;
int n, m;
int a[101][101];
int d[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void bfs (int x, int y) {
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(x, y));
    while (!dq.empty()) {
        tie(x, y) = dq.front();
        dq.pop_front();
        for (int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if (a[nx][ny] == 0 && d[nx][ny] == -1) {//빈방
                    dq.push_front(make_pair(nx, ny));
                    d[nx][ny] = d[x][y];
                }else if (a[nx][ny] == 1 && d[nx][ny] == -1) { //벽
                    dq.push_back(make_pair(nx, ny));
                    d[nx][ny] = d[x][y] + 1;
                }
            }
        }
    }
}
int main () {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    memset(d, -1, sizeof(d));
    d[1][1] = 0;
    bfs(1, 1);
    printf("%d", d[n][m]);
    return 0;
}