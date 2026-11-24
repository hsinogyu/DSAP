#include <bits/stdc++.h>
using namespace std;

int N, X;
int arr[100005];
int hap[2000005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> X;
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (X > arr[i]) {
            hap[arr[i]] = 1;
            if (X - arr[i] != arr[i] && hap[X - arr[i]] == 1) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

// 반례: 10 - 5 = 5 | 차가 자신인 경우 짝이 없는 거로 생각해야함