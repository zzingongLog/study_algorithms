#include <iostream>
using namespace std;
bool prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main () {
    int n;
    cin >> n;
    int cnt = 0;
    int input;
    while (n--) {
        cin >> input;
        if(prime(input)) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}