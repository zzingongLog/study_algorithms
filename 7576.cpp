#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;
int d[1000][1000];
int a[1000][1000];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
//1:익은토마토 0:안익은토마토 -1:토마토없음
int main () {
    scanf("%d %d", &m, &n);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            d[i][j] = -1;
            if (a[i][j] == 1) {
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }
     while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (a[nx][ny] == 0 && d[nx][ny] == -1) {
                    q.push(make_pair(nx, ny)); 
                    d[nx][ny] = d[x][y] + 1;
                }
            }
        }
    }   
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans < d[i][j]) ans = d[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && d[i][j] == -1) {
                ans = -1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}