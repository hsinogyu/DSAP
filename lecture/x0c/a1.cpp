#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10]; // 수열을 담을 배열
bool isused[10]; // 특정 수를 사용했는지 확인하는 배열

void func(int k) { // 현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수
    if (k == M) { // k == M이면 모든 수를 선택했으므로 출력함
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1; // 사용했다는 표시를 남김
            func(k + 1); // 다음 수를 찾기
            isused[i] = 0; // 사용했다는 표시를 다시 지움
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    func(0);

    return 0;
}
