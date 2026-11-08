#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
bool isused1[15]; // y
bool isused2[30]; // x + y
bool isused3[30]; // x - y + N - 1

void func(int k) { // cur번째 행에 말을 배치할 예정
    if (k == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isused1[i] || isused2[k + i] || isused3[k - i + N - 1]) continue;

        isused1[i] = true;
        isused2[k + i] = true;
        isused3[k - i + N - 1] = true;
        func(k + 1);
        isused1[i] = false;
        isused2[k + i] = false;
        isused3[k - i + N - 1] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    func(0);
    cout << ans << '\n';

    return 0;
}
