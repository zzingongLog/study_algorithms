#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int d[11];
int main () {
    int nums[] = {1, 2, 3};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(d, 0, sizeof(d));
        d[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i - nums[j] >= 0) {
                    d[i] += d[i - nums[j]];
                }
            }
        }
        cout << d[n] << '\n';
    }
    return 0;
}
