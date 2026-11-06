#include <bits/stdc++.h>
using namespace std;

int N, R, C;

int func(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1);

    if (r < half && c < half) {
        return func(n-1, r, c);
    } else if (r < half && c >= half) {
        return half * half + func(n-1, r, c - half);
    } else if (r >= half && c < half) {
        return 2 * half * half + func(n-1, r - half, c);
    } else {
        return 3 * half * half + func(n-1, r - half, c - half);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> C;
    cout << func(N, R, C) << '\n';

    return 0;
}
