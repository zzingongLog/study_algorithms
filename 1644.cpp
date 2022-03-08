#include <iostream>
#include <vector>
using namespace std;
int main () { 
    int n;
    cin >> n;
    vector<bool> check(n + 1);
    vector<int> primes;
    check[0] = check[1] = true;
    for (int i = 2; i <= n; i++) {
        if (check[i] == false) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                check[j] = true;
            }
        }
    }
   
    int ans = 0;
    int sum = primes.empty() ? 0 : primes[0];
    int left = 0;
    int right = 0;
    while (left <= right && right < primes.size()) {
        if (n > sum) {
            right += 1;
            sum += primes[right];
        } else if (n == sum) {
            ans += 1;
            right += 1;
            sum += primes[right];
        } else if (n < sum) {
            sum -= primes[left];
            left += 1;
            if (left > right && left < primes.size()) {
                right = left;
                sum = primes[left];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}