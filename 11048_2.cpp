#include <iostream>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    d[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //아래
            if (i + 1 <= n && d[i + 1][j] < d[i][j] + a[i + 1][j]) {
                d[i + 1][j] = d[i][j] + a[i + 1][j];
            }
            //대각선
            if (i + 1 <= n && j + 1 <= m && d[i + 1][j + 1] < d[i][j] + a[i + 1][j + 1]) {
                d[i + 1][j + 1] =  d[i][j] + a[i + 1][j + 1];
            }
            //오른쪽
            if (j + 1 <= m && d[i][j + 1] < d[i][j] + a[i][j + 1]) {
                d[i][j + 1] = d[i][j] + a[i][j + 1];
            }
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}