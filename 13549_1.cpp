#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
const int MAX = 100000;
int d[MAX + 1];
void bfs (int x) {
    deque<int> dq;
    dq.push_back(x);
    d[x] = 0;
    while(!dq.empty()) {
        x = dq.front();
        dq.pop_front();
        if (x * 2 <= MAX && d[x * 2] == -1) {
            dq.push_front(x * 2);
            d[x * 2] = d[x];
        }
        if (x + 1 <= MAX && d[x + 1] == -1) {
            dq.push_back(x + 1);
            d[x + 1] = d[x] + 1;
        }
        if (x - 1 >= 0 && d[x - 1] == -1) {
            dq.push_back(x - 1);
            d[x - 1] = d[x] + 1;
        }
    }
}
int main () {
    int n, k;
    cin >> n >> k;
    memset(d, -1, sizeof(d));
    bfs (n);
    cout << d[k] << '\n';
    return 0;
}