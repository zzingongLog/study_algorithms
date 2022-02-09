#include <iostream>
using namespace std;
bool check[1000001]; //지워졌으면 true
int main(){
    check[0] = check[1] = true; //0, 1은 지운다
    int m, n;
    cin >> m >> n;
    for (int i = 2; i * i <= n; i++) {
        if (check[i] == false) { //지워지지 않았다면 소수이므로
            for (int j = i * 2; j <= n; j += i) { //그 수의 배수를 전부 지운다
                check[j] = true;
            }    
        }
    }
    for (int i = m; i <= n; i++) { //지워지지 않은 수를 출력한다
        if(!check[i]) cout << i << '\n';
    }
    return 0;
}