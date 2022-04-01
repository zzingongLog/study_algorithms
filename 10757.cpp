#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int A[10001];
int B[10001];
int ans[10001];
int main () {
    string a, b;
    cin >> a >> b;
    int an = a.size();
    for (int i = 0; i < an; i++) {
        A[i] = a[an - i - 1] - '0';
    }
    int bn = b.size();
    for (int i = 0; i < bn; i++) {
        B[i] = b[bn - i - 1] - '0';
    }
    int n = max(an, bn);
    int carring = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] + carring > 9) {
            ans[i] = A[i] + B[i] + carring - 10;
            carring = 1;
        } else {
            ans[i] = A[i] + B[i] + carring;
            carring = 0;
        }
        if (carring != 0 && i + 1 >= n) {
            n++;
        }
    }
    reverse(ans, ans + n);
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}