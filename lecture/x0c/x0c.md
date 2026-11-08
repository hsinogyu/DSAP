# 백트래킹

## 알고리즘 설명

### 백트래킹
- 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘

### 상태 공간 트리
- 가능한 경우의 수를 나열하며 트리의 구조를 나타내는 형태

---
## 연습 문제 1 - N과 M

### 상태에 대한 개념 (N = 4, M = 3)
- 1
    - 1 2
        - 1 2 3
        - 1 2 4
    - 1 3
        - 1 3 2
        - 1 3 4
    - 1 4
        - 1 4 2
        - 1 4 3

- 2
    - ...

### BOJ 15649번: N과 M (1)
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10]; // 수열을 담을 배열
bool isused[10]; // 특정 수를 사용했는지 확인하는 배열

void func(int k) { // 현재 k개까지 수를 택한 상황에서 arr[k]를 정하는 함수
    if (k == M) { // k == M이면 모든 수를 선택했으므로 출력함
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1; // 사용했다는 표시를 남김
            func(k + 1); // 다음 수를 찾기
            isused[i] = 0; // 사용했다는 표시를 다시 지움 - 여기서 사용했다는 것을 지우고 다음 수로 넘어가게 되니, 이 수를 사용할 수 있게 됨
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    func(0);

    return 0;
}
```

---
## 연습 문제 2 - N-Queen

### BOJ 9663번: N-Queen
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, ans;
int board[15][15];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void visited_true(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        while (!(nx < 0 || nx >= N || ny < 0 || ny >= N)) {
            board[nx][ny]++;
            nx = nx + dx[i];
            ny = ny + dy[i];
        }
    }
}

void visited_false(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        while (!(nx < 0 || nx >= N || ny < 0 || ny >= N)) {
            board[nx][ny]--;
            nx = nx + dx[i];
            ny = ny + dy[i];
        }
    }
}

void func(int k) {
    if (k == N) {
        ans++;
        return;
    }

    for (int j = 0; j < N; j++) {
        if (board[k][j] == 0) {
            visited_true(k, j);
            func(k + 1);
            visited_false(k, j);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    func(0);
    cout << ans << '\n';

    return 0;
}
```
- 핵심 아이디어: 0이 아닌 수가 있으면 방문했다고 판단
- 퀸을 뺄 경우 해당 퀸의 공격 범위를 빼기 (다른 퀸이 점유하고 있는 공간은 그대로 두는 것)

### 더 좋은 아이디어
- 현재 위에 코드는 퀸이 놓이는 좌표 기준으로 탐색을 쭉함
- 또한 기존 코드의 시간 복잡도: O(N! * N)
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
bool isused1[15]; // y
bool isused2[30]; // x + y
bool isused3[30]; // x - y + N - 1

void func(int k) { // cur번째 행에 말을 배치할 예정
    if (k == N) {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isused1[i] || isused2[k + i] || isused3[k - i + N - 1]) continue;

        isused1[i] = true;
        isused2[k + i] = true;
        isused3[k - i + N - 1] = true;
        func(k + 1);
        isused1[i] = false;
        isused2[k + i] = false;
        isused3[k - i + N - 1] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    func(0);
    cout << ans << '\n';

    return 0;
}
```
- 핵심 아이디어
    - 사용 중인 열에는 절대 놓을 수 없음 => (x, y)를 접근하면 해당 y는 이제부터 놓을 수 없음
    - 사용중인 `/` 대각선은 절대 놓을 수 없음 => x+y가 같은면 같은 대각선에 놓여있다고 판단
    - 사용중인 `\` 대각선은 절대 놓을 수 없음 => x-y가 같으면 같은 대각선에 놓여있다고 판단
        - 배열로 접근하게 된다면 배열의 인덱스에는 음수를 사용할 수 없음
        - 따라서 보강을 해주어야함
        - x-y의 가장 작은 값(0 - (N-1))을 기준으로 인덱스를 0으로 부여
            - x - y + (N - 1)로 0으로 만듦

- 시간 복잡도: O(N!)
    - 근데 실제로 돌려보면 좀 더 빨리나옴
    - 이미 할 수 없는 경우가 있기 때문: **가지치기**
    - 가지치기가 빈번하면 시간복잡도를 가늠하기 쉽지 않음
    - N이 많이 작은 경우 고려해볼만함(N <= 11)

---
## 연습 문제 3 - 부분 수열의 합

### BOJ 1182번: 부분 수열의 합
- 원소가 n개인 집합에서 부분집합의 갯수는 2^n(공집합 포함)
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, S, ans;
int board[20];

void func(int k, int sum) {
    if (k > 0 && sum == S) {
        ans++;
    }
    
    if (k == N) { // 사실상 없어도 됨
        return;
    }

    for (int i = k; i < N; i++) {
        func(i + 1, sum + board[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        board[i] = input;
    }

    func(0, 0);
    cout << ans << '\n';

    return 0;
}
```

### 조금 더 좋은 접근
- 한쪽은 원소를 넣지 않았을 때 / 한쪽은 원소를 넣었을 때로 상태 공간 트리를 구분
- 즉, 매 순간 수를 더할지 말지를 선택
- 주의할 점: 공집합은 포함되지 않도록 조절해야함(원소를 전부 넣지 않았을 경우가 공집함)
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, S, ans;
int board[20];

void func(int k, int sum) { // 현재까지 사용한 원소의 위치와 그 합
    if (k == N) {
        if (sum == S) {
            ans++;
        }
        return;
    }

    // 현재 가리키고 있는 원소를 더하지 않는 경우
    func(k + 1, sum);

    // 현재 가리키고 있는 원소를 더하는 경우
    func(k + 1, sum + board[k]);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        board[i] = input;
    }

    func(0, 0);
    if (S == 0) {
        ans--;
    }
    cout << ans << '\n';

    return 0;
}
```

---
## STL next_permutation

### 예제
- 순열 처리
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3] = {1, 2, 3};

    do {
        for (int i = 0; i < 3; i++) {
            cout << a[i];
        }
        cout << '\n';
    } while (next_permutation(a, a + 3));

    return 0;
}
```

- 조합 처리
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[4] = {0, 0, 1, 1};

    do {
        for (int i = 0; i < 4; i++) {
            cout << i + 1;
        }
        cout << '\n';
    } while (next_permutation(a, a + 4));

    return 0;
}
```
