#include <queue>
#include <cstdio>
using namespace std;
const int MAX = 100001;
int d[MAX];
bool check[MAX];
void bfs(int x) {
    queue<int> q;
    q.push(x); 
    check[x] = true;
    while (!q.empty()) {
        x = q.front(); q.pop();
        if (x + 1 <= MAX && check[x + 1] == false) {
            q.push(x + 1);
            check[x + 1] = true;
            d[x + 1] = d[x] + 1;
        }
        if (x - 1 >= 0 && check[x - 1] == false) {
            q.push(x - 1);
            check[x - 1] = true;
            d[x - 1] = d[x] + 1;
        }
        if (x * 2 <= MAX && check[x * 2] == false) {
            q.push(x * 2);
            check[x * 2] = true;
            d[x * 2] = d[x] + 1;
        }
    }
    
}
int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    bfs(n);
    printf("%d", d[k]);
    return 0;
}