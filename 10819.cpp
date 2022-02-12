#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc(vector<int> &a) {
    int sum = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        sum += abs(a[i] - a[i + 1]); 
    }
    return sum;
}
int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    do {
        int t = calc(a);
        if(ans < t) ans = t; 
    } while(next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
    return 0;
}