#include <iostream>
using namespace std;
long long mod = 1000000000;
long long d[201][201];
int main () {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = d[i - 1][j];
            if(j - 1 >= 0) {
                d[i][j] += d[i][j - 1];
            }
            d[i][j] %= mod;
        }
    }
    cout << d[k][n] << '\n';
    return 0;
}