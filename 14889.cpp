#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n / 2; i++) {
        b[i] = 1;
    }
    sort(b.begin(), b.end());
    int ans = 2147483647;
    do {
        vector<int> first, second;
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                first.push_back(i);
            }else {
                second.push_back(i);
            }
        }
        int one = 0;
        int two = 0;
        for (int i = 0 ; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (i == j) continue;
                one += s[first[i]][first[j]];
                two += s[second[i]][second[j]];
            }
        }
        int diff = abs (one - two);
        if (ans > diff) ans = diff;
    } while(next_permutation(b.begin(), b.end()));
    cout << ans << '\n';
    return 0;
}