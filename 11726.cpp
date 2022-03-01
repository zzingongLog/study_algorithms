#include <iostream>
using namespace std;
int d[1001];
int go (int n) {
    if (n == 1) return 1;
    if (d[n] > 0) return d[n];
    d[n] = (go (n - 1) + go (n - 2)) % 10007;
    return d[n];
}
int main () {
    int n;
    cin >> n;
    d[0] = 1;
    d[1] = 1;
    cout << go(n) << '\n';
    return 0;
}