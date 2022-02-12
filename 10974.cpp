#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    //배열에 이미 순서대로 정렬되어 들어간 상태
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    do {
        for (int t : arr) cout << t << ' ';
        cout << '\n';
    }while (next_permutation(arr.begin(), arr.end()));
    return 0;
}