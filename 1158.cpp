//요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;
int main () {
    int n, k; // 1부터 n명의 사람을 순서대로 k번째 사람을 제거
    cin >> n >> k; 
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    cout << '<';
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << '>' << '\n';
    return 0;
}