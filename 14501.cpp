#include <iostream>
using namespace std;
int n;
int t[15];
int p[15];
int ans;
void go(int sum, int day) {
    if (day > n) return;
    if (day == n) { //퇴사일
        if (ans < sum) ans = sum;
        return;
    }
    go(sum + p[day], day + t[day]); //상담하는 경우
    go(sum, day + 1); //상담 안하는 경우
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }
    go(0, 0);
    cout << ans << '\n';
    return 0;
}