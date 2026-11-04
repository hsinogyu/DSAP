#include <bits/stdc++.h>
using namespace std;

int box[1002][1002];
int N, M;
queue<pair<int, int>> Q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init_box() {
    for (int i = 0; i < 1002; i++) {
        fill(box[i], box[i] + 1002, 0);
    }

    while (!Q.empty()) {
        Q.pop();
    }

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int input;
            cin >> input;
            box[i][j] = input;
            if (input == 1) {
                Q.push({i, j});
            }
        }
    }
}

void bfs() {
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (box[nx][ny] > 0 || box[nx][ny] == -1) continue;

            box[nx][ny] = box[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
}

int check_box() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] > ans) {
                ans = box[i][j];
            }

            if (box[i][j] == 0) {
                return 0;
            }
        }
    }
    return ans;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_box();
    bfs();
    cout << check_box() - 1 << '\n';

    return 0;
}
