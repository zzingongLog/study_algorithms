#include <iostream>
#include <vector>
using namespace std;
bool next_permutation(int *a, int n) {
    //1.a[i-1] < a[i] 를 만족하는 i찾기
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i]) i -= 1;
    //i가 0임에도 1번 조건을 찾을 수 없다면 순열이 전부 내림차순 이라는 의미.(= 마지막 순열) 
    if (i <= 0) return false; //마지막 순열은 다음 순열이 없으므로 false를 리턴
    //2.A[j] > A[i -1] 를 만족하는 가장 큰 j 찾기
    int j = n - 1;
    while (a[j] <= a[i - 1]) j -= 1;
    //3.i-1번째 수와 j번째 수를 서로 교환하기
    swap(a[i - 1], a[j]);
    //4.a[i]부터 끝까지 순열을 뒤집기
    j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1; j -= 1; //i부터 증가, j는 끝에서부터 감소
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
    if (next_permutation(arr, n)) {
        for (int t : arr) cout << t << ' ';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
