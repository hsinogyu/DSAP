#include <bits/stdc++.h>
using namespace std;

int board[15][15];
int N, R, C;
int cnt;

void search() {
    if () {
        board[][] = cnt++;
    }

    search();
    search();
    search();
    search();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> C;
    search();
    cout << board[R][C] << '\n';

    return 0;
}
