#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr1[1000001];
int arr2[1000001];
int arr3[2000002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr1[i];
    for (int i = 0; i < M; i++) cin >> arr2[i];

    int p1 = 0, p2 = 0;
    for (int i = 0; i < N + M; i++) {
        if (p2 == M) arr3[i] = arr1[p1++];
        else if (p1 == N) arr3[i] = arr2[p2++];
        else if (arr1[p1] < arr2[p2]) arr3[i] = arr1[p1++];
        else arr3[i] = arr2[p2++];
    }

    for (int i = 0; i < N + M; i++) {
        cout << arr3[i] << '\n';
    }

    return 0;
}