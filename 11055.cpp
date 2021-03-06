#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        d[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + a[i]) {
                d[i] = d[j] + a[i];
            }
        }
    }
    cout << *max_element(d.begin(), d.end());
    return 0;
}