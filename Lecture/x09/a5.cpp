#include <bits/stdc++.h>
using namespace std;

int N, K;

int dist[100002];
int dx[3] = {-1, 1, 2};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(dist, dist + 100002, -1);

    cin >> N >> K;
    queue<int> Q;
    dist[N] = 0;
    Q.push(N);        

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 3; dir++) {
            int nx = (dir != 2) ? cur + dx[dir] : cur * dx[dir];
            
            if (nx < 0 || nx > 100000) continue;
            if (dist[nx] > -1) continue;

            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }

    cout << dist[K] << '\n';

    return 0;
}
