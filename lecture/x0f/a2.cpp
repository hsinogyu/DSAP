#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[5] = {1, 4, 5, 2, 7};
    sort(a, a + 5);
    
    vector<int> b = {1, 4, 5, 2, 7};
    sort(b.begin(), b.end());
    // sort(b.begin(), b.begin() + 5);

    return 0;
}
