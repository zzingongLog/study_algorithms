#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int s[20][20];
int n;
int go (int index, vector<int> &first, vector<int> &second) {
    if (index == n) {
        if (first.size() != n / 2) return -1;
        if (second.size() != n / 2) return -1;
        int t1 = 0;
        int t2 = 0; 
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (i == j) continue;
                t1 += s[first[i]][first[j]];
                t2 += s[second[i]][second[j]];
            }
        }
        return abs(t1 - t2);
    }
    int ans = -1;
    first.push_back(index);
    int t1 = go (index + 1, first, second);
    //ans에 값이 대입이 한번도 안되었거나, t1이 불가능하지 않거나 t1(팀간차이값)이 ans보다 작을 때
    if (ans == -1 || (t1 != -1 && ans > t1)) { 
        ans = t1;
    }
    first.pop_back();
    second.push_back(index);
    int t2 = go (index + 1, first, second);
    if (ans == -1 || (t2 != -1 && ans > t2)) {
        ans = t2;
    }
    second.pop_back();
    return ans;
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }    
    }
    vector<int> first, second;
    cout << go (0, first, second) << '\n';
    return 0;
}