#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int go (int n, int m) {
    if (n < 1 || m < 1) return 0;
    if (d[n][m] >= 0) {
        return d[n][m];
    }
    d[n][m] = max(go(n - 1, m), go(n, m - 1)) + a[n][m];
    return d[n][m];
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << go(n, m) << '\n';
    return 0;
}