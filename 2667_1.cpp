#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[25][25];
int d[25][25];
int ans[25*25];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs (int x, int y, int cnt) {
    d[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (d[nx][ny] == 0 && a[nx][ny] == 1) {
                dfs (nx, ny, cnt);
            }
        }
    }
}
int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && d[i][j] == 0) {
                dfs (i, j, ++cnt);
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[d[i][j]] += 1;
        }
    }
    sort (ans + 1, ans + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        printf("%d\n", ans[i]);
    }
    return 0; 
}