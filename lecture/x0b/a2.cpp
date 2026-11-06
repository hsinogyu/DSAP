#include <bits/stdc++.h>
using namespace std;

int N;

void func(int n, int src, int dst) {
    if (n == 1) {
        cout << src << ' ' << dst << '\n';
        return;
    }

    func(n - 1, src, 6 - src - dst);
    cout << src << ' ' << dst << '\n';
    func(n - 1, 6 - src - dst, dst);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cout << (1 << N) - 1 << '\n';
    func(N, 1, 3);

    return 0;
}
