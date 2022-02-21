#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[10]; int a[10];
vector<vector<int>> d;
void go (int index, int start, int n, int m) {
    if (index == m) {
        vector<int> t;
        for (int i = 0; i < m; i++) {
            t.push_back(num[a[i]]);
        }
        d.push_back(t);
        return;
    }
    for (int i = start; i < n; i++) {
        a[index] = i;
        go (index + 1, i + 1, n, m);
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
    d.erase(unique(d.begin(), d.end()), d.end()); //중복제거
    for (auto &v : d) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}