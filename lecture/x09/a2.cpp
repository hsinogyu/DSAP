#include <bits/stdc++.h>
using namespace std;

int board[502][502];
int dist[502][502];
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char input;
            cin >> input;
            board[i][j] = input - '0';
        }
    }
    
    queue<pair<int, int>> Q;
    dist[0][0] = 1;
    Q.push({0, 0});

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] != 0 || board[nx][ny] == 0) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}
