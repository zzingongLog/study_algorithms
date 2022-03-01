#include <iostream>
using namespace std;
int d[11];
int go(int n) {
    if (d[n] > 0) return d[n];
    d[n] = go (n - 1) + go (n - 2) + go (n - 3);
    return d[n];
}
int main () {
    int t;
    cin >> t;
    d[0] = d[1] = 1;
    d[2] = 2;
    while(t--) {
        int n;
        cin >> n;
        cout << go (n) << '\n';
    }
    return 0;
}