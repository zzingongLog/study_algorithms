#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc (vector<int> &a, vector<int> &op) {
    int ans = a[0];
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == 0) { //더하기
            ans += a[i + 1];
        }else if(op[i] == 1) { //빼기
            ans -= a[i + 1];
        }else if(op[i] == 2) { //곱하기
            ans *= a[i + 1];
        }else { //나누기
            ans /= a[i + 1];
        }
    }
    return ans;
}
int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> op;
    for (int i = 0; i < 4; i++) { //+, -, *, / 연산자 순서대로 0,1,2,3 
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            op.push_back(i); //연산자 번호를 개수만큼 저장
        }
    }
    int max = -1e9; //-10억
    int min = 1e9; //10억
    do {
        int t = calc(a, op);
        if (max < t) max = t;
        if (min > t) min = t;
    } while (next_permutation(op.begin(), op.end()));
    
    cout << max << '\n';
    cout << min << '\n';
    
    return 0;
}