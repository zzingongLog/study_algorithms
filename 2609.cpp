#include <iostream>
using namespace std;
int gcd (int a, int b) {
    if (a % b != 0) {
        return gcd(b, a % b);
    }else {
        return b;
    }
}
int lcm (int a, int b) {
    return a * b / gcd(a, b);
}
int main () {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';
    return 0;
}