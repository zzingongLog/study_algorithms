#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a(1001);
vector<int> v(1001);
vector<int> d(1001);
void print (int n) {
    if (n == -1) return;
    print(v[n]);
    cout << a[n] << ' ';
}
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        v[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                v[i] = j;
            }
        }
    }
    int index = 0;
    int max = d[0];
    for (int i = 0; i < n; i++) {
        if (d[i] > max) {
            max = d[i];
            index = i;
        }
    }
    cout << max << '\n';
    print(index);
    return 0;
}