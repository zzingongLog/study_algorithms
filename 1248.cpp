#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int sign[10][10];
int ans[10];
bool ok () {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += ans[j];
            if (sign[i][j] == 0) {
                if (sum != 0) return false;
            } else if (sign[i][j] == 1) {
                if (sum <= 0) return false;
            } else {
                if (sum >= 0) return false;
            }
        }
    }
    return true;
}
bool go (int index) {
    if (index == n) {
        return ok ();
    }
    for (int i = -10; i <= 10; i++) { //시간초과
        ans[index] = i;
        if (go (index + 1)) return true;
    }
    return false;
}
int main () {
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (s[cnt] == '0') {
                sign[i][j] = 0;
            } else if (s[cnt] == '+') {
                sign[i][j] = 1;
            } else {
                sign[i][j] = -1;
            }
            cnt += 1;
        }
    }
    go (0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}