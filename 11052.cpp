#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n; //구매하려고 하는 카드의 개수
    cin >> n;
    vector<int> p(n + 1);
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        d[i] = -1;
    }
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (d[i] == -1 || d[i] > d[i - j] + p[j]) {
                d[i] = p[j] + d[i - j];
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}