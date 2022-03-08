#include <iostream>
using namespace std;
int main () {
    int a, b, c;
    cin >> a >> b >> c;
    if (b + c >= 60) {
        a += ((b + c) / 60);
        if (a >= 24) a -= 24;
        b = (b + c) % 60;
    }else {
        b += c;
    }
    cout << a << ' ' << b;
    return 0;
}