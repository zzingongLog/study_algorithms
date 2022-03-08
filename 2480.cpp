#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a == b  && b == c) {
        ans = 10000 + (1000 * a);
    } else if (a != b && b != c && c != a) {
        ans = max(max(a, b), c) * 100;
    } else {
        if (a == b) {
            ans = 1000 + a * 100;
        } else if (b == c) {
            ans = 1000 + b * 100;
        } else if (a == c) {
            ans = 1000 + a * 100;
        } 
    }
    cout << ans << '\n';
    return 0;
}
