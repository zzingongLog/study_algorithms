#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int d[100000];
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (d[i - 1] + a[i] > a[i]) {
            d[i] = d[i - 1] + a[i];
        }else {
            d[i] = a[i];
        }
    }
    cout << *max_element(d, d + n) << '\n';
    return 0;
}