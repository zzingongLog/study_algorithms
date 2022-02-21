#include <iostream>
#include <algorithm>
using namespace std;
int num[10]; int a[10];
void go (int index, int start, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << a[i];
            if (i != m - 1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++) {
        a[index] = num[i];
        go (index + 1, i, n, m);
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    int temp[10];
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    sort (temp, temp + n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && temp[i] == temp[i - 1]) continue;
        num[k++] = temp[i];
    }
    n = k;
    go (0, 0, n, m);
    return 0;
} 