#include <iostream>
using namespace std;
const long long mod = 1000000000LL;
long long d[101][10];
int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) d[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j - 1 >= 0) {
                d[i][j] += d[i - 1][j - 1];
            }
            if (j + 1 <= 9) {
                d[i][j] += d[i - 1][j + 1];
            }
            d[i][j] %= mod;
        }
    }    
    long long ans = 0;
    for (int i = 0; i <= 9; i++) ans += d[n][i];
    ans %= mod;
    cout << ans << '\n';
    return 0;
}