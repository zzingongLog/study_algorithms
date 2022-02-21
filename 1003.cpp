#include <iostream>
#include <cstring>
using namespace std;
int a[41];
int fibonacci(int n) {
    if (n == 0){
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        if (a[n] > 0) {
             return a[n];
        } else {
            a[n] = fibonacci(n - 1) + fibonacci(n - 2);
            return a[n];
        }
    }
}
int main () {
    int t;
    cin >> t;
    a[0] = 0;
    a[1] = 1;  
    while(t--) {
        int n;
        cin >> n;
        fibonacci(n);
        if(n == 0) 
            cout << 1 << ' ' << 0 << '\n';
        else if(n == 1) 
            cout << 0 << ' ' << 1 << '\n';
        else
            cout << fibonacci(n - 1) << ' ' << fibonacci(n) << '\n';
    }
    return 0;
}