#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long func(long long A, long long B, long long C) {
    if (B == 0) return 1 % C; // B가 만약 0을 넣을 수 있다면
    if (B == 1) return A % C;

    long long half = func(A, B/2, C);
    long long result = (half * half) % C;

    if (B % 2 == 0) {
        return result;
    } else {
        return (result * (A % C)) % C;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;
    cout << func(A, B, C) << '\n';

    return 0;
}
