#include <iostream>
#include <algorithm>
using namespace std;
int a[10]; int num[10];
void go(int index, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i];
            if (i != m) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        a[index] = num[i];
        go(index + 1, n, m);
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    go(0, n, m);
    return 0;
}