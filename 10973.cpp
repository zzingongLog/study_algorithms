#include <iostream>
using namespace std;
bool prev_permutation(int *a, int n) {
    int i = n - 1;
    while (i > 0 && a[i - 1] <= a[i]) i -= 1;
    if (i <= 0) return false; // 첫순열
    int j = n - 1;
    while (a[j] >= a[i - 1]) j -= 1;
    swap(a[i - 1], a[j]);
    j = n - 1;
    while (i < j) {
        swap (a[i], a[j]);
        i++; j--;
    }
    return true; 
}
int main () {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (prev_permutation(arr, n)) {
        for (int t : arr) cout << t << ' ';
    }else cout << -1;
    cout << '\n';
    return 0;
}