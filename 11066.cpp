#include <cstring>
#include <cstdio>
using namespace std;
int a[501];
int d[501][501];
int go (int i, int j) {
    if (i == j) return 0;
    if (d[i][j] != -1) return d[i][j];
    int &ans = d[i][j];
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += a[k];
    }
    for (int k = i; k <= j - 1; k++) {
        int temp = go(i, k) + go(k + 1, j) + sum;
        if (ans == -1 || ans > temp) {
            ans = temp;
        }
    }
    return ans;
}
int main () {
    int t;
    scanf("%d", &t);
    while(t--) {
        int k;
        scanf("%d", &k);
        memset(d, -1, sizeof(d));
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", go(1, k));
    }
    return 0;
}