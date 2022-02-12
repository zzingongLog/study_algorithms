#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int k;
    while(cin >> k) {
        if (k == 0) break;
        vector<int> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        vector<int> t;
        for (int i = 0; i < k - 6; i++) {
            t.push_back(0); //로또가 당첨되지 않을 자리 0
        }
        for (int i = 0; i < 6; i++) {
            t.push_back(1); //로또가 당첨될 자리 1
        }
        vector<vector<int>> ans;
        do {
            vector<int> now;
            for (int i = 0; i < k; i++) {
                if (t[i] == 1) { //1인 자리의 수가 당첨된 것이므로 그 수를 now에 저장
                    now.push_back(arr[i]);
                } 
            }
            ans.push_back(now);
        }while (next_permutation(t.begin(), t.end()));
        //오름차순으로 정렬
        sort(ans.begin(), ans.end());
        //출력
        for (auto &v : ans) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}