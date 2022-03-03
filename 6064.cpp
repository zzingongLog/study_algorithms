#include <iostream>
using namespace std;
int main () {
    int t;
    cin >> t;
    int m, n, x, y;
    while (t--) {
        cin >> m >> n >> x >> y;
        x--; y--;
        bool ok = false;
        for (int i = x; i < m * n; i += m) {
            if (i % n == y) {
                cout << i + 1 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        }
    }
    return 0;
}