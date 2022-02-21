#include <iostream>
#include <algorithm>
using namespace std;
int a[10]; bool c[10]; int num[10];
void go (int index, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << num[i];
            if (i != m) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (c[i]) continue;
        c[i] = true; num[index] = a[i];
        go (index + 1, n, m);
        c[i] = false;
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a, a + n);
    go(0, n, m);
    return 0;
}