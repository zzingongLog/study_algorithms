#include <cstdio>
int n;
int a[2000];
bool d[2000][2000];
int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {// 팰린드롬 길이가 1인것은 무조건 true
        d[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) { //팰린드롬 길이가 2인것은 둘다 같아야 true
        if (a[i] == a[i + 1]) {
            d[i][i + 1] = true;
        }
    }
    for (int k = 3; k <= n; k++) { //팰린드롬 길이 3부터 채워나가기
        for (int i = 0; i <= n - k; i++) { //시작
            int j = i + k - 1; //끝점
            if (a[i] == a[j] && d[i + 1][j - 1]) {
                d[i][j] = true;
            }
        }
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", d[s - 1][e - 1]);
    }
    return 0;
}