#include <iostream>
using namespace std;
bool broken[10];
int possible (int c) {
    if (c == 0) return broken[0] ? 0 : 1;
    int len = 0;
    while (c > 0) {
        if (broken[c % 10]) {
            return 0;
        }else {
            len += 1;
            c /= 10;
        }
    }
    return len;
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        broken[b] = true;
    }
    int ans = abs(n - 100);
    for (int i = 0; i <= 1000000; i++) {
        int len = possible(i);
        if (len > 0) {
            if (ans > len + abs(n - i)) {
                ans = len + abs(n - i);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}