#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int a[101][101];
int n, m;
int dist[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y)); 
    dist[x][y] = 1;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if (a[nx][ny] == 1 && dist[nx][ny] == 0) {
                    q.push(make_pair(nx, ny)); dist[nx][ny] = dist[x][y] + 1;
                }
            }
        } 
    }
}
int main () {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    bfs(1, 1);
    printf("%d\n", dist[n][m]);
    return 0;
}