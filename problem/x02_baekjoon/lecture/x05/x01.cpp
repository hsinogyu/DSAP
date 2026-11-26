#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> S;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int num;
            cin >> num;
            S.push(num);
        } else if (input == "pop") {
            if (S.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        } else if (input == "size") {
            cout << S.size() << '\n';
        } else if (input == "empty") {
            cout << (S.empty() ? 1 : 0) << '\n';
        } else if (input == "top") {
            if (S.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << S.top() << '\n';
            }
        }
    }

    return 0;
}
