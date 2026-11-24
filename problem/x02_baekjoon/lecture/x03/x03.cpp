#include <bits/stdc++.h>
using namespace std;

string N;
int arr[10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N.size(); i++) {
        int idx = N[i] - '0';
        if (idx == 6 && arr[idx] > arr[9]) {
            arr[9]++;
        } 
        else if (idx == 9 && arr[idx] > arr[6]) {
            arr[6]++;
        }
        else {
            arr[idx]++;
        }
    }

    int mx = 0;
    for (int i = 0; i < 10; i++) {
        if (mx < arr[i]) {
            mx = arr[i];
        }
    }

    cout << mx << '\n';

    return 0;
}

// - 6과 9를 한 칸에 몰아서 센 뒤에 즉 둘을 합 한 값 + 1을 2로 나누면 그 값을 나중에 최댓값이랑 비교 - 즉, 최댓값 비교를 6, 9를 제외한 나머지를 구한 후 마지막에 처리
