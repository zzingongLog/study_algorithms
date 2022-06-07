#include <cstdio>
int a[101];
int d[10001];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    d[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - a[i] >= 0) {
                d[j] += d[j - a[i]];
            }
        }   
    }
    printf("%d\n", d[k]);
    return 0;
}