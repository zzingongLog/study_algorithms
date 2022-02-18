#include <iostream>
#include <string>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    int s = 0;
    while(m--) {
        string cmd;
        cin >> cmd;
        int x;
        if (cmd == "add") {
            cin >> x; x--;
            s = s | (1 << x);
        } else if (cmd == "remove") {
            cin >> x; x--;
            s = s & ~(1 << x);
        } else if (cmd == "check") {
            cin >> x; x--;
            if (s & (1 << x)) cout << 1;
            else cout << 0;
            cout << '\n';
        } else if (cmd == "toggle") {
            cin >> x; x--;
            s = s ^ (1 << x);
        } else if (cmd == "all") { //전체집합
            s = (1 << 20) - 1;
        } else { //공집합
            s = 0;
        }
    }
    return 0;
}