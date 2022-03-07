#include <iostream>
#include <string>
#include <vector>
using namespace std;
int count(int mask, vector<int> &words) {
    int cnt = 0;
    for (int word : words) {
        if ((word & ((1 << 26) - 1 - mask)) == 0) {
            cnt += 1;
        }
    }
    return cnt;
}
int go (int index, int k, int mask, vector<int> &words) {
    if (k < 0) return 0;
    if (index == 26) {
        return count(mask, words);
    }
    int ans = 0;
    //mask에 배운 글자를 비트마스크로 기록
    int t1 = go (index + 1, k - 1, mask | (1 << index), words); //배우는 경우의 수
    if (ans < t1) ans = t1; //최대값 구하기
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') { //배우지 않는 경우의 수
        t1 = go (index + 1, k, mask, words);
        if (ans < t1) ans = t1;
    }
    return ans;
}
int main () {
    int n, k; //n개의 단어, k개의 글자 가르침
    cin >> n >> k;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char x : s) {
            words[i] |= (1 << (x - 'a')); //i번째에 존재하는 문자들을 비트마스크로 추가
        }
    }
    cout << go (0, k, 0, words) << '\n';
    return 0;
}