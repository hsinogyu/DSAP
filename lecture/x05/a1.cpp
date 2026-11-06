#include <bits/stdc++.h>
using namespace std;

void test() {
    stack<int> S;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "push") {
            // 정수 X
            int input;
            cin >> input;
            S.push(input);
        } else if (command == "pop") {
            if (S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
                S.pop();
            }
        } else if (command == "size") {
            cout << S.size() << '\n';
        } else if (command == "empty") {
            if (S.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (command == "top") {
            if (S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}
