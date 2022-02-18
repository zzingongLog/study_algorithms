#include <iostream>
using namespace std;
int main () {
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) { //전체 집합 
        int sum = 0;
        for (int k = 0; k < n; k++) { //0~n-1 자리 체크
            if (i & (1 << k)) { //검사
                sum += a[k];
            }
        }
        if (sum == s) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}