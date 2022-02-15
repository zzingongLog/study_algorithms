#include <iostream>
#include <vector>
using namespace std;
pair<int, int> go(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div){
    int n = a.size();
    if (index == n) {
        return make_pair(cur, cur);
    }
    vector<pair<int, int>> res;
    if (plus > 0) {
        res.push_back(go(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
    }
    if (minus > 0) {
        res.push_back(go(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
    }
    if (mul > 0) {
        res.push_back(go(a, index + 1, cur * a[index], plus, minus, mul - 1, div));
    }
    if (div > 0) {
        res.push_back(go(a, index + 1, cur / a[index], plus, minus, mul, div - 1));
    }
    auto ans = res[0];
    for (auto p : res) {
        if (ans.first < p.first) { //최대
            ans.first = p.first;
        }
        if (ans.second > p.second) { //최소
            ans.second = p.second;
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
    int op[4];
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    auto p = go(a, 1, a[0], op[0], op[1], op[2], op[3]);
    cout << p.first << '\n';
    cout << p.second << '\n';
    return 0;
}