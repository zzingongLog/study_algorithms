#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        d[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
    }
    cout << *max_element(d, d + n) << '\n';
    return 0;
}