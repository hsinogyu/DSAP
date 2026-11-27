#include <bits/stdc++.h>
using namespace std;

int N;

void init() {
    cin >> N;
}

void process() {
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        if (input == "push") {
            int num; cin >> num;
            Q.push(num);
        }
        else if (input == "pop") {
            if (Q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (input == "size") {
            cout << Q.size() << '\n';
        }
        else if (input == "empty") {
            if (Q.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (input == "front") {
            if (Q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << Q.front() << '\n';
            }
        }
        else if (input == "back") {
            if (Q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << Q.back() << '\n';
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    process();

    return 0;
}