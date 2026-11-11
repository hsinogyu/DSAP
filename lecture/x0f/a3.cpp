#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    if (a % 5 != b % 5) return a % 5 < b % 5;
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    sort(a, a + 7, cmp);

    return 0;
}
