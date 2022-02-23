#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 100000;
int d[MAX + 1];
void bfs (int x) {
    queue<int> q;
    queue<int> next_q;
    q.push(x);
    d[x] = 0;
    while(!q.empty()) {
        x = q.front();
        q.pop();
        if (x * 2 <= MAX && d[x * 2] == -1) {
            q.push(x * 2); 
            d[x * 2] = d[x];
        }
        if (x - 1 >= 0 && d[x - 1] == -1) {
            next_q.push(x - 1);
            d[x - 1] = d[x] + 1;
        }
        if (x + 1 <= MAX && d[x + 1] == -1) {
            next_q.push(x + 1);
            d[x + 1] = d[x] + 1;
        }
        if (q.empty()) {
            q = next_q;
            next_q = queue<int>();
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