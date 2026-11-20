// BOJ 10808번: 알파벳 개수 - 성공
#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        char idx = input[i] - 'a';
        arr[idx]++;
    }
    
    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
