#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> Q;

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        Q.push(i);
    }
}

void process() {
    while (Q.size() != 1) {
        Q.pop();

        int top_element = Q.front(); Q.pop();
        Q.push(top_element);
    }

    cout << Q.front() << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    process();

    return 0;
}