#include <iostream>
using namespace std;
int a[20];
int n, s;
int go (int index, int sum) {
    if (index == n) {
        if (sum == s) {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    ans += go(index + 1, sum + a[index]);
    ans += go(index + 1, sum);
    return ans;
}
int main () {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = go(0, 0);
    if (s == 0) 
        cout << ans - 1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}