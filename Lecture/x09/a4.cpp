#include <bits/stdc++.h>
using namespace std;

char board[1002][1002];
int dist1[1002][1002];
int dist2[1002][1002];
int R, C;

queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init_board() {
    while (!Q1.empty()) {
        Q1.pop();
    }

    while (!Q2.empty()) {
        Q2.pop();
    }

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        fill(dist1[i], dist1[i] + C, -1);
        fill(dist2[i], dist2[i] + C, -1);
        for (int j = 0; j < C; j++) {
            char input;
            cin >> input;
            board[i][j] = input;
            if (input == 'F') {
                dist1[i][j] = 0;
                Q1.push({i, j});
            }

            if (input == 'J') {
                dist2[i][j] = 0;
                Q2.push({i, j});
            }
        }
    }
}

void bfs_f() {
    while (!Q1.empty()) {
        pair<int, int> cur = Q1.front(); Q1.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (board[nx][ny] == '#' || dist1[nx][ny] > -1) continue;

            dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
            Q1.push({nx, ny});
        }
    }
}

void bfs_j() {
    while (!Q2.empty()) {
        pair<int, int> cur = Q2.front(); Q2.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << dist2[cur.first][cur.second] + 1 << '\n';
                return;
            }
            if (board[nx][ny] == '#' || dist2[nx][ny] > -1) continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;

            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            Q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_board();  
    bfs_f();
    bfs_j();  

    return 0;
}
