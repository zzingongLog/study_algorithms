#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[10]; int a[10];
vector<vector<int>> d;
void go (int index, int start, int n, int m) {
    if (index == m){
        vector<int> t;
        for (int i = 0; i < m; i++) {
            t.push_back(a[i]);
        }
        d.push_back(t);
        return;
    }
    for (int i = start; i < n; i++) {
        a[index] = num[i];
        go (index + 1, start, n, m);
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort (num, num + n);
    go (0, 0, n, m);
    sort (d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    for (auto &v : d) {
        for (int i = 0; i < m; i++) {
            cout << v[i];
            if (i != m - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}