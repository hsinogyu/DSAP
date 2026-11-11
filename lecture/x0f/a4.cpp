#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> V(100005);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    
    sort(V.begin(), V.begin() + N); // O(NlgN)

    int cnt = 0;
    long long mxval = -(1ll << 62) - 1;
    int mxcnt = 0;
    for (int i = 0; i < N; i++) { // O(N)
        if (i == 0 || V[i - 1] == V[i]) cnt++;
        else {
            if (cnt > mxcnt) { // `>`인 이유: 같은 크기면 작은 수를 선택(현재 오름차순 정렬 사용)
                mxcnt = cnt;
                mxval = V[i - 1];
            }
            cnt = 1;
        }
    }

    if (cnt > mxcnt) mxval = V[N - 1]; // 제일 마지막 수에 대한 처리 - 마지막 구간의 경우 갱신을 하지 않고 나오므로
    cout << mxval << '\n';

    return 0;
}

// 시간 복잡도: O(NlgN)
