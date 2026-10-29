#include <bits/stdc++.h>
using namespace std;

int func2(vector<int> v, int n) {
    int hap[100] = {0, };

    for (int i = 0; i < n; i++) {
        if (hap[100 - v[i]] == 1) {
            return 1;
        }
        hap[v[i]] = 1;
    }

    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << func2({1, 52, 48}, 3) << '\n';
    cout << func2({50, 42}, 2) << '\n';
    cout << func2({4, 13, 63, 87}, 4) << '\n';

    return 0;
}
