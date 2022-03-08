#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int left = 0;
    int right = 0;
    int ans = n + 1;
    int len = 1;
    int sum = a[0];
    while (left <= right && right < n) {
        if (sum < s) {
            right += 1;
            len += 1;
            sum += a[right];
        } else if (sum == s) {
            if (len < ans) ans = len;
            right += 1;
            len += 1;
            sum += a[right];
        } else if (sum > s) {
            if (len < ans) ans = len;
            sum -= a[left];
            len -= 1;
            left += 1;
        }
    }
    if (ans > n) ans = 0;
    cout << ans << '\n';
    return 0;
}