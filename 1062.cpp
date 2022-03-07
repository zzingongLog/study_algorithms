#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool learn[26]; //알파벳 나열 순서대로 배운 여부를 저장
int count(vector<string> &words) {
    int cnt = 0;
    for (string word : words) {
        bool ok = true;
        for (char x : word) {
            if (!learn[x - 'a']) {
                ok = false;
                break;
            }
        }
        if (ok) cnt += 1;
    }
    return cnt;
}
int go (int index, int k, vector<string> &words) {
    if (k < 0) return 0;
    if (index == 26) {
        return count(words);
    }
    int ans = 0;
    learn[index] = true;
    int t1 = go (index + 1, k - 1, words);
    learn[index] = false;
    if (ans < t1) ans = t1; //최대값 구하기
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') {
        t1 = go (index + 1, k, words);
        if (ans < t1) ans = t1;
    }
    return ans;
}
int main () {
    int n, k; //n개의 단어, k개의 글자 가르침
    cin >> n >> k;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cout << go (0, k, words) << '\n';
    return 0;
}