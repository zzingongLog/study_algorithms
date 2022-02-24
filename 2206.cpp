#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int a[1000][1000];
int d[1000][1000][2];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void bfs (int x, int y, int z) {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x, y, z));
    while(!q.empty()) {
        tie(x, y, z) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (a[nx][ny] == 0 && d[nx][ny][z] == 0) {
                    d[nx][ny][z] = d[x][y][z] + 1;
                    q.push(make_tuple(nx, ny, z));
                }
                if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z + 1] == 0) {
                    d[nx][ny][z + 1] = d[x][y][z] + 1;
                    q.push(make_tuple(nx, ny, z + 1));
                }
            }
        }
    }
}
int main () {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    d[0][0][0] = 1; //시작하는 칸
    bfs(0, 0, 0);
    //출력
    if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0) {
        printf("%d", min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]));
    }else if (d[n - 1][m - 1][0] != 0) {
        printf("%d", d[n - 1][m - 1][0]);
    }else if (d[n - 1][m - 1][1] != 0) {
        printf("%d", d[n - 1][m - 1][1]);
    }else {
        printf("-1");
    }
    return 0;
}