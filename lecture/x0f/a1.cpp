#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2000002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        arr[input + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i - 1000000 << '\n';
        }
    }

    return 0;
}
