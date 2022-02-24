#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
char map[50][50]; //map
int water[50][50]; //물차는 시간
int s[50][50]; //고슴도치 이동 시간 
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main () {
    int r, c;
    cin >> r >> c;
    int sx, sy;
    int ex, ey;
    memset(water, -1, sizeof(water));
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%1s", &map[i][j]);
            if (map[i][j] == '*') { //물
                q.push(make_pair(i, j));
                water[i][j] = 0;
            }else if (map[i][j] == 'S') { //비버위치 
                sx = i; 
                sy = j;
            }else if (map[i][j] == 'D') {
                ex = i;
                ey = j;
            }
        }
    }
    //물번지는 시간
    while (!q.empty()) {
        int x, y;
        tie (x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (map[nx][ny] == 'X') continue;
                if (map[nx][ny] == 'D') continue;
                if (water[nx][ny] == -1) {
                    q.push(make_pair(nx, ny));
                    water[nx][ny] = water[x][y] + 1;
                }                
            }
        }
    }
    //비버이동시간
    memset(s, -1, sizeof(s));
    q.push(make_pair(sx, sy));
    s[sx][sy] = 0;
    while (!q.empty()) {
        int x, y;
        tie (x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                if (map[nx][ny] == 'X') continue;
                if (water[nx][ny] != -1 && s[x][y] + 1 >= water[nx][ny]) continue;
                if (s[nx][ny] == -1) {
                    s[nx][ny] = s[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    if (s[ex][ey] == -1) {
        cout << "KAKTUS\n";
    } else {
        cout << s[ex][ey] << '\n';
    }
    return 0;
}