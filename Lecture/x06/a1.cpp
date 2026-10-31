#include <bits/stdc++.h>
using namespace std;

void test() {
    queue<int> Q;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string command; cin >> command;
        if (command == "push") {
            int value; cin >> value;
            Q.push(value);
        } else if (command == "pop") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if (command == "size") {
            cout << Q.size() << '\n';
        } else if (command == "empty") {
            cout << (int)Q.empty() << '\n';
        } else if (command == "front") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
            }
        } else if (command == "back") {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.back() << '\n';
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