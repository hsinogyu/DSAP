#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    stack<pair<int, int>> S;

    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;

        while (!S.empty() && S.top().second < height) {
            S.pop();
        }

        if (S.empty()) {
            cout << 0 << ' ';
        }
        else {
            cout << S.top().first << ' ';
        }

        S.push({i, height});
    }
    cout << '\n';

    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[500001];

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int find_mx_idx(int cur) {
    int mx = arr[cur];
    for (int i = cur - 1; i >= 0; i--) {
        if (arr[i] >= mx) {
            return i + 1;
        }
    }
    return 0;
}

void process() {
    cout << 0 << ' ';
    for (int i = 1; i < N; i++) {
        cout << find_mx_idx(i) << ' ';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    process();

    return 0;
}
*/
