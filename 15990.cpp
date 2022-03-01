#include <iostream>
using namespace std;
long long d[100001][4];
const long long mod = 1000000009LL;
int main () {
    for (int i = 0; i < 100001; i++) {
        for (int j = 1; j < 4; j++) {
            if (i < j) {
                d[i][j] = 0;
            }else if (i == j) {
                d[i][j] = 1;
            }else {
                if (j == 1) {
                    d[i][j] = (d[i - 1][2] + d[i - 1][3]) % mod;
                }else if (j == 2) {
                    d[i][j] = (d[i - 2][3] + d[i - 2][1]) % mod;
                }else {
                    d[i][j] = (d[i - 3][1] + d[i - 3][2]) % mod; 
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
    }
    return 0;
}