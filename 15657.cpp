#include <iostream>
#include <algorithm>
using namespace std;
int num[10]; int a[10];
void go (int index, int start, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i];
            if (i != m) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++) {
        a[index] = num[i];
        go (index + 1, i, n, m);
    }
}
int cnt[10]; //i번째에 숫자를 선택한 개수
void go2 (int index, int selected, int n, int m) {
    if (selected == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                cout << num[i] << ' ';
            }
        }
        cout << '\n';
        return;
    }
    if (index >= n) return;
    for (int i = m - selected; i >= 1; i--) { //선택 한거
        cnt[index] = i;
        go2 (index + 1, selected + i, n, m);
    }
    cnt[index] = 0; //선택 안한거
    go2 (index + 1, selected, n, m);
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort (num, num + n);
    go (0, 0, n, m);
    go2 (0, 0, n, m);
   return 0;
}