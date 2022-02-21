#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[10]; int a[10]; int cnt[10];
void go (int index, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << num[a[i]];
            if (i != m) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) {
            cnt[i] -= 1;
            a[index] = i;
            go (index + 1, n, m);
            cnt[i] += 1;
        }
    }
}
int main () {
    int n, m;
    cin >> n >> m;
    int temp[10];
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    sort (temp, temp + n);
    int k = 0; //중복을 제거한 실제 수를 계산하기 위한 인덱스 k
    int x = temp[0]; //비교하는 두개의 값 중 앞의 값
    int c = 1; //중복된 개수
    for (int i = 1; i < n; i++) {
        if (x == temp[i]) {
            c += 1;
        } else {
            num[k] = x;
            cnt[k] = c;
            k += 1;
            x = temp[i];
            c = 1;
        }
    }
    num[k] = x;
    cnt[k] = c;
    n = k + 1; //중복을 제거한 실제 개수
    go (0, n, m);
    return 0;
}