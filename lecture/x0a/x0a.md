# DFS

## 알고리즘 설명

### DFS(Depth First Search)
- 다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘

---
## 예시

### 과정
1. 시작하는 칸을 방문했다는 표시를 남기고 스택에 넣음
2. 스택에서 원소를 꺼내어 그 칸과 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌 때까지 2번을 반복
- 모든 칸이 스택에 1번씩 들어가므로 시간복잡도는 칸이 N개일 때 O(N)

> 큐를 쓰면 BFS / 스택을 쓰면 DFS - 방문 순서에서 아주 큰 차이가 있음

### 구현
```cpp
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];

int n = 7, m = 10;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<pair<int, int>> S;
    vis[0][0] = true;
    S.push({0, 0});

    while (!S.empty()) {
        pair<int, int> cur = S.top(); S.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            S.push({nx, ny});
        }
    }

    return 0;
}
```
