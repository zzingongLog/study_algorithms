#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int LIMIT = 5;
vector<int> gen (int k) {
    vector<int> a(LIMIT);
    for (int i = 0; i < LIMIT; i++) {
        a[i] = (k & 3);
        k >>= 2;
    }
    return a;
}
int check (vector<vector<int>> &a, vector<int> &dirs) {
    int n = a.size();
    vector<vector<pair<int, bool>>> d(n, vector<pair<int, bool>>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j].first = a[i][j];
        }
    }
    // 0: down, 1: up, 2: left, 3: right
    for (int dir : dirs) {
        bool ok = false;
        for (int i = 0; i < n; i++) { //초기화
            for (int j = 0; j < n; j++) {
                d[i][j].second = false;
            }
        }
        while (true) {
            ok = false;
            if (dir == 0) {
                for (int i = n - 2; i >= 0; i--) {
                    for (int j = 0; j < n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i + 1][j].first == 0) { //아래로 내려가는데 아래값이 0이면 그냥 숫자를 이동시킴
                            d[i + 1][j].first = d[i][j].first;
                            d[i + 1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i + 1][j].first == d[i][j].first){
                            if (d[i + 1][j].second == false && d[i][j].second == false) {
                                d[i + 1][j].first *= 2;
                                d[i + 1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 1) {
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i - 1][j].first == 0) {
                            d[i - 1][j].first = d[i][j].first;
                            d[i - 1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i - 1][j].first == d[i][j].first) {
                            if (d[i - 1][j].second == false && d[i][j].second == false) {
                                d[i - 1][j].first *= 2;
                                d[i - 1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            } else if (dir == 2) {
                for (int j = 1; j < n; j++) {
                    for (int i = 0; i < n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j - 1].first == 0) {
                            d[i][j - 1].first = d[i][j].first;
                            d[i][j - 1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j].first == d[i][j - 1].first){
                            if (d[i][j].second == false && d[i][j - 1].second == false) {
                                d[i][j - 1].first *= 2;
                                d[i][j - 1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
                
            } else if (dir == 3) {
                for (int j = n - 2; j >= 0; j--) {
                    for (int i = 0; i < n; i++) {
                        if (d[i][j].first == 0) continue;
                        if (d[i][j + 1].first == 0) {
                            d[i][j + 1].first = d[i][j].first;
                            d[i][j + 1].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        } else if (d[i][j].first == d[i][j + 1].first) {
                            if (d[i][j].second == false && d[i][j + 1].second == false) {
                                d[i][j + 1].first *= 2;
                                d[i][j + 1].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            }
            if (ok == false) break;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans < d[i][j].first) {
                ans = d[i][j].first;
            }
        }
    }
    return ans;
}
int main () {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int k = 0; k < (1 << (2 * LIMIT)); k++) {
        vector<int> dirs = gen(k);
        int cur = check(a, dirs);
        if (ans < cur) ans = cur;
    }
    cout << ans << '\n';
    return 0;
}