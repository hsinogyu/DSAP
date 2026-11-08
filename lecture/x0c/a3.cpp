#include <bits/stdc++.h>
using namespace std;

int N, S, ans;
int board[20];

void func(int k, int sum) { // 현재까지 사용한 원소의 위치와 그 합
    if (k == N) {
        if (sum == S) {
            ans++;
        }
        return;
    }

    // 현재 가리키고 있는 원소를 더하지 않는 경우
    func(k + 1, sum);

    // 현재 가리키고 있는 원소를 더하는 경우
    func(k + 1, sum + board[k]);
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
    if (S == 0) {
        ans--;
    }
    cout << ans << '\n';

    return 0;
}
