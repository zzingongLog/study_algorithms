#include <cstring>
#include <iostream>
using namespace std;
int d[10000];
int main () {
    int nums[] = {1, 2, 3}; //임의의 순서를 만들어서 그 순서로 이루어진 합만 만들어준다.(중복제거)
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(d, 0, sizeof(d));
        d[0] = 1;
        for (int j = 0; j < 3; j++) { //사용해야 하는 수
            for (int i = 1; i <= n; i++) { //만들어야 하는 수
                if (i - nums[j] >= 0) {
                    d[i] += d[i - nums[j]]; 
                }
            }
        }
        printf("%d\n", d[n]);
    }
    return 0;
}