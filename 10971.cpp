#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> a(n); //도시번호저장
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    int cost[n][n]; //cost[i][j] = i번 도시에서 j번 도시로 가기 위한 비용
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    //최소값 초기화 주의
    int ans = 2147483627;
    do {
        bool isOk = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cost[a[i]][a[i + 1]] == 0) {
                isOk = false;
                break;
            } else {
                sum += cost[a[i]][a[i + 1]];
            }
        }
        //마지막 도시에서 원래 도시로 돌아올 수 있는지 체크
        if (isOk && cost[a[n - 1]][a[0]] != 0) {
            sum += cost[a[n - 1]][a[0]];
            if (ans > sum) ans = sum;
        }
    } while(next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
    return 0;
}