#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    for (char c : input) {
        arr[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
