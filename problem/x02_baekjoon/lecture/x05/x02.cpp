#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100000];

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void process() {
    stack<int> S;
    vector<char> V;
    int idx = 1;
    for (int i = 0; i < N; i++) {
        int cur = arr[i];
        while (idx <= cur) {
            S.push(idx++);
            V.push_back('+');
        }

        if (S.top() == cur) {
            S.pop();
            V.push_back('-');
        }
        else {
            cout << "NO" << '\n';
            return;
        }
    }

    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    process();

    return 0;
}
