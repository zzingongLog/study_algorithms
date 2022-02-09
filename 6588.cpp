#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX + 1];
int main () {
    check[0] = check[1] = true;
    for (int i = 2; i * i <= MAX; i++) {
        if (check[i] == false) {
            for (int j = i * 2; j <= MAX; j += i) {
                check[j] = true;
            }
        }
    }
    ios_base::sync_with_stdio(false); //매우 많은 입력이 주어질때 속도가 느려짐을 방지
    cin.tie(nullptr);
    int n;
    while(cin >> n) {
        bool flag = false;
        if (n == 0) break;
        for (int i = 3; i < n; i += 2) {
            if (!check[i] && !check[n - i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) cout << "Goldbach's conjecture is wrong." << '\n';
    }
    return 0;
}