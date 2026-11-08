#include <bits/stdc++.h>
using namespace std;

int N, S, ans;
int board[20];

void func(int k, int sum) {
    if (k > 0 && sum == S) {
        ans++;
    }
    
    if (k == N) {
        return;
    }

    for (int i = k; i < N; i++) {
        func(i + 1, sum + board[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        board[i] = input;
    }

    func(0, 0);
    cout << ans << '\n';

    return 0;
}
