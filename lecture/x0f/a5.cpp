#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<long long, int> m;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        m[x]++; // 키가 없으면 자동으로 0을 만듦
    }

    long long mxval = 0;
    int mxcnt = 0;
    // for (auto& [val, cnt] : m) {
    //     if (cnt > mxcnt) { // 같은 결우 원래 값 유지: map은 key 기준으로 자동 정렬이 되어있음 => 작은 수부터 순회
    //         mxcnt = cnt;
    //         mxval = val;
    //     }
    // }

    for (pair<const long long, int>& p : m) {
        if (p.second > mxcnt) {
            mxcnt = p.second;
            mxval = p.first;
        }
    }

    cout << mxval << '\n';

    return 0;
}
