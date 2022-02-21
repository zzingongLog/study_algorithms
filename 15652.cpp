#include <iostream>
using namespace std;
int a[10];
void go (int index, int start, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i];
            if (i != m - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        a[index] = i;
        go (index + 1, i, n, m);
    }
}
int cnt[10];
void go2(int index, int selected, int n, int m) {
    if (selected == m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }
    if (index > n) return;
    for (int i = m - selected; i >= 1; i--) { //선택하는거
        cnt[index] = i;
        go2(index + 1, selected + i, n, m);
    }
    cnt[index] = 0; //선택을 안하는거
    go2(index + 1, selected, n, m);
}
int main () {
    int n, m;
    cin >> n >> m;
    go (0, 1, n, m);
    go2 (1, 0, n, m);
    return 0;
}