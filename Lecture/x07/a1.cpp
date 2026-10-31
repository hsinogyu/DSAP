#include <bits/stdc++.h>
using namespace std;

void test() {
    deque<int> DQ;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string command; cin >> command;
        if (command == "push_front") {
            int value; cin >> value;
            DQ.push_front(value);
        } else if (command == "push_back") {
            int value; cin >> value;
            DQ.push_back(value);
        } else if (command == "pop_front") {
            if (DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        } else if (command == "pop_back") {
            if (DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        } else if (command == "size") {
            cout << DQ.size() << '\n';
        } else if (command == "empty") {
            cout << (int)DQ.empty() << '\n';
        } else if (command == "front") {
            if (DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.front() << '\n';
            }
        } else if (command == "back") {
            if (DQ.empty()) {
                cout << -1 << '\n';
            } else {
                cout << DQ.back() << '\n';
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
