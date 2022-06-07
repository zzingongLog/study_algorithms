#include <iostream>
using namespace std;
int a[100][100];
long long d[100][100];
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) continue;
            if (a[i][j] + j < n) {
                d[i][a[i][j] + j] += d[i][j];
            }
            if (a[i][j] + i < n) {
                d[a[i][j] + i][j] += d[i][j];
            }
        }
    }
    cout << d[n - 1][n - 1] << '\n';
    return 0;
}