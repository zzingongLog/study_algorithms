#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dl[n];
    dl[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (dl[i - 1] + a[i] > a[i]) {
            dl[i] = dl[i - 1] + a[i];
        }else {
            dl[i] = a[i];
        }
    }
    int dr[n];
    dr[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (dr[i + 1] + a[i] > a[i]) {
            dr[i] = dr[i + 1] + a[i];
        }else {
            dr[i] = a[i];
        }
    }
    int ans = *max_element(dl, dl + n);
    for (int i = 1; i < n - 1; i++) {
        if (ans < dl[i - 1] + dr[i + 1]) {
            ans = dl[i - 1] + dr[i + 1];
        }
    }
    cout << ans << '\n';
    return 0;
}