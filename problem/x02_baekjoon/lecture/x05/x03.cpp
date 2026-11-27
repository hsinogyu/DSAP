#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    stack<pair<int, int>> S;

    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;

        while (!S.empty() && S.top().second < height) {
            S.pop();
        }

        if (S.empty()) {
            cout << 0 << ' ';
        }
        else {
            cout << S.top().first << ' ';
        }

        S.push({i, height});
    }
    cout << '\n';

    return 0;
}
