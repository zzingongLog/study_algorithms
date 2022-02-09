#include <iostream>
using namespace std;
int gcd (int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[101];
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}