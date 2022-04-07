#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int n, m;
int go(int x, int y) {
    if (x > n || y > m) return 0;
    if (d[x][y] >= 0) return d[x][y];
    d[x][y] = max(go(x + 1, y), go(x, y + 1)) + a[x][y];
    return d[x][y];
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << go(1, 1) << '\n';
    return 0;
}