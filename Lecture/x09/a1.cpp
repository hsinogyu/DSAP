#include <bits/stdc++.h>
using namespace std;

int board[502][502];
int vis[502][502];
int N, M;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void init_board() {
    for (int i = 0; i < 502; i++) {
        fill(board[i], board[i] + 502, 0);
        fill(vis[i], vis[i] + 502, 0);
    }

    cin >> N >> M;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            int input;
            cin >> input;
            board[x][y] = input;
        }
    }
}

int BFS(int x, int y) {
    int size = 0;

    queue<pair<int, int>> Q;

    vis[x][y] = 1;
    Q.push({x, y});

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        size++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    return size;
}

void test() {
    int cnt = 0;
    int mx = 0;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (board[x][y] == 1 && vis[x][y] != 1) {
                int breadth = BFS(x, y);
                if (mx < breadth) {
                    mx = breadth;
                }
                cnt++;
            }
        }
    }

    cout << cnt << '\n' << mx << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_board();
    test();

    return 0;
}
