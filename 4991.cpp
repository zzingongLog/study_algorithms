#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> bfs(vector<string> &a, int sx, int sy) {
    int h = a.size();
    int w = a[0].size();
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    dist[sx][sy] = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (dist[nx][ny] == -1 && a[nx][ny] != 'x') {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return dist;
}
int main () {
    while (true) {
        int h, w;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<string> a(h);
        for (int i = 0; i < h; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> b(1);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (a[i][j] == 'o') {
                    b[0] = make_pair(i, j);
                } else if (a[i][j] == '*'){
                    b.push_back(make_pair(i, j));
                }
            }
        }
        int l = b.size();
        vector<vector<int>> d(l, vector<int>(l)); //2차원 백터.l개의 원소에서 각 원소(vector)는 l개의 원소를 갖고 있음
        bool ok = true;
        for (int i = 0; i < l; i++) { //로봇청소기 위치 + 더러운칸 개수
            auto dist = bfs(a, b[i].first, b[i].second); //각 위치(i)에 bfs를 한다.
            for (int j = 0; j < l; j++) { 
                d[i][j] = dist[b[j].first][b[j].second];//d[i][j] : 시작 위치(i)에서 더러운 점(j)까지 최소방문거리 저장 
                if (d[i][j] == -1) { //방문할 수 없는 경우
                    ok = false;
                }
            }
        }
        if (ok == false) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> p(l - 1);
        for (int i = 0; i < l - 1; i++) {
            p[i] = i + 1;
        }
        int ans = -1;
        do {
            int now = d[0][p[0]];
            for (int i = 0; i < l - 2; i++) {
                now += d[p[i]][p[i + 1]];
            }
            if (ans == -1 || ans > now) {
                ans = now;
            }
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << '\n';        
    }
    return 0;
}