#include <bits/stdc++.h>
using namespace std;

string test(string input) {
    stack<char> S;
    for (char c : input) {
        if (c == '(') {
            S.push(c);
        } else if (c == '[') {
            S.push(c);
        } else if (c == ')') {
            // 스택이 비어있을 때, no
            if (S.empty()) {
                return "no";
            }

            // 스택이 비어있지 않은데, 맞지 않을 때, no
            if (S.top() != '(') {
                return "no";
            }

            S.pop();
        } else if (c == ']') {
            // 스택이 비어있을 때, no
            if (S.empty()) {
                return "no";
            }

            // 스택이 비어있지 않은데, 맞지 않을 때, no
            if (S.top() != '[') {
                return "no";
            }

            S.pop();
        }
    }

    if (S.empty()) {
        return "yes";
    } else {
        return "no";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        string input;
        getline(cin, input);
        if (input == ".") break;

        cout << test(input) << '\n';
    }

    return 0;
}
