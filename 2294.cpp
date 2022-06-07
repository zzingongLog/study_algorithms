#include <cstdio>
int a[101];
int d[10001];
int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= k; i++) {
        d[i] = -1;
    }
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - a[i] >= 0 && d[j - a[i]] != -1) {
                if (d[j] == -1 || d[j] > d[j - a[i]] + 1) { //최소 동전의 개수 체크
                    d[j] = d[j - a[i]] + 1;
                }
            }
        }
    }
    printf("%d\n", d[k]);
    return 0;
}