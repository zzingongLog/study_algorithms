#include <iostream>
#include <vector>
#include <string>
using namespace std;
//0 : -> , 1: <- , 2: 아래, 3: 위
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int LIMIT = 10; //10회까지만 움직이기 가능
vector<int> gen (int k) { //4진법으로 변환
    vector<int> a(LIMIT);
    for (int i = 0; i < LIMIT; i++) {
        a[i] = (k & 3);
        k >>= 2;
    }
    return a;
}
bool valid (vector<int> &dir) {
    int l = dir.size();
    for (int i = 0; i + 1 < l; i++) {
        if (dir[i] == dir[i + 1]) return false; //같은방향
        if (dir[i] == 0 && dir[i + 1] == 1) return false; //좌, 우
        if (dir[i] == 1 && dir[i + 1] == 0) return false;
        if (dir[i] == 2 && dir[i + 1] == 3) return false; //아래, 위
        if (dir[i] == 3 && dir[i + 1] == 2) return false;
    }
    return true;
}
//return : 움직인 여부, 구멍에 들어간 여부
pair<bool, bool> simulate (vector<string> &a, int k, int &x, int &y) {
    if (a[x][y] == '.') return make_pair(false, false);
    int n = a.size();
    int m = a[0].size();
    bool moved = false;
    while (true) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            return make_pair(moved, false);
        }
        if (a[nx][ny] == '#') {
            return make_pair(moved, false);
        } else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') {
            return make_pair(moved, false);
        } else if (a[nx][ny] == '.') {
            swap(a[nx][ny], a[x][y]);
            x = nx;
            y = ny;
            moved = true;
        } else if (a[nx][ny] == 'O') {
            a[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }
    return make_pair(false, false); //여기는 절대 닿지 않음
}
//판에 구슬을 옮겨보는데 옮기는 것이 가능한지 아닌지 여부를 판단
int check (vector<string> a, vector<int> &dir) {//판을 복제해서 사용할 것이라 &가 붙지 않음
    int n = a.size();
    int m = a[0].size();
    int hx, hy, rx, ry, bx, by;
    //구멍, 파란구슬, 빨간 구슬의 좌표를 기록
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'O') {
                hx = i, hy = j;
            } else if (a[i][j] == 'R') {
                rx = i, ry = j;
            } else if (a[i][j] == 'B') {
                bx = i; by = j;
            }
        }
    }
    int cnt = 0;
    for (int k : dir) {
        cnt += 1;
        bool hole1 = false, hole2 = false;
        while (true) {
            auto p1 = simulate(a, k, rx, ry);
            auto p2 = simulate(a, k, bx, by);
            if (p1.first == false && p2.first == false) break; //둘다 안움직인다면 break;
            if (p1.second) hole1 = true;
            if (p2.second) hole2 = true;
        }
        if (hole2) return -1; //파란구슬이 들어가면 실패
        if (hole1) return cnt;
    }
    return -1;
}
int main () {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = -1;
    for (int k = 0; k < (1 << (LIMIT * 2)); k++) {
        vector<int> dir = gen(k); //k를 방향으로 전환
        if (!valid(dir)) continue; //이 방향이 유효한지 확인
        int cur = check(a, dir);
        if (cur == -1) continue;
        if (ans == -1 || ans > cur) ans = cur; //최소값
    }
    cout << ans << '\n';
    return 0;
}