# 정렬

## Counting Sort

### 문제
- `[1, 5, 4, 2, 3, 1, 2, 3]`을 정렬하고 싶은 경우
    - 그냥 정렬 알고리즘을 사용하면 됨
    - 시간 복잡도: O(N^2) ~ O(NlgN)

### 새로운 접근 방법
| 1 | 2 | 3 | 4 | 5 |
| --- | --- | --- | --- | --- |
| 2 | 1 | 2 | 2 | 1 |
- 각 수가 몇 번 나왔는지를 기록
- **1부터 나온 횟수만큼 출력만 하면 정렬 끝** => `Counting Sort`

### 주의사항
- 막 사용할 수 있는 것이 아니라 사용할 수 있는 상황이 존재함
- 이론적으로 수의 범위가 0 ~ 1억
- 보통 1000만 이하일 때 사용

### BOJ 15688번: 수 정렬하기 5
```cpp
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2000002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        arr[input + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i - 1000000 << '\n';
        }
    }

    return 0;
}
```
- 시간 복잡도:
    - 수의 범위가 K라고 할 때, 맨 처음 N개의 수를 보면서 값을 추가
    - 답을 출력할 때, 총 K개의 칸을 확인하고 출력
    - `O(N + K)`

- 공간 복잡도:
    - `O(K)`

---
## Radix Sort

### 개념
- 자릿수를 이용해서 정렬을 수행하는 알고리즘(카운팅 소트를 응용한 알고리즘)

### 흐름
- `[012, 421, 046, 674, 103, 502, 007, 100, 021, 545]`
    - 0 ~ 9까지 리스트를 생성
    - 1의 자리에 따라서 수를 넣음
    - 다시 꺼내서 수를 재배열함
        - 1의 자리 수를 기준으로 재배열됨
        - **같은 수는 원래의 위치를 그대로 가지고 있음**
    - 10의 자리에 따라서 수를 넣음
    - 다시 꺼내서 수를 재배열함
        - 10의 자리 수를 기준으로 재배열됨
    - 100의 자리에 따라서 수를 넣음
    - 다시 꺼내서 수를 재배열함
        - 100의 자리 수를 기준으로 재배열됨 => `정렬 완료`

### 가능한 이유
- 421 < 502
    - 100의 자리를 비교
    - 10의 자리를 비교
    - 1의 자리를 비교

### 시간 복잡도
- 자릿수의 최대 개수가 D개라고 할 때, D번에 거쳐서 카운팅 소트를 하는 것과 동일함
- O(D(N + K))
    - 근데 리스트에 개수 K가 매우 작음
    - `O(DN)`

### 맹점
- 공간의 낭비가 너무 심함
- STL을 사용할 수 있는 상황이면 STL sort를 사용하면 됨
- 구현해야하면 list, vector 등을 구현해야하는데 복잡함
- **개념 이해만 하고 넘어가도 됨**

### Comparison Sort vs Non-comparison Sort
- Comparison Sort(원소를 비교하면서 정렬함)
    - 버블 소트
    - 머지 소트
    - 퀵 소트

- Non-Comparison Sort(원소를 비교하지 않고 정렬함)
    - 카운팅 소트
    - 라딕스 소트

---
## STL Sort

### 예시 코드
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[5] = {1, 4, 5, 2, 7};
    sort(a, a + 5);
    
    vector<int> b = {1, 4, 5, 2, 7};
    sort(b.begin(), b.end());
    // sort(b.begin(), b.begin() + 5);

    return 0;
}
```

### 주의사항
- sort 함수는 `stable sort`가 아님!!
- 필요하다면 `stable_sort()`함수를 사용
- **pair, tuple**은 이미 대소 관계가 익숙한대로 먼저 제일 앞의 것을 비교하고 이후 뒤에 것을 비교하도록 내부적으로 구현되어있음

### 비교 함수
- 원하는 형태로 비교를 진행하게 할 수 있음
```cpp
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    if (a % 5 != b % 5) return a % 5 < b % 5;
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    sort(a, a + 7, cmp);

    return 0;
}
```
- a가 b의 앞에 와야할 때 true를 그렇지 않을 때 false를 반환해야함

### 매우 주의사항
- 비교 함수는 두 값이 같을 때(혹은 위선순위가 같을 때) false를 반환해야함!!!
    - 런타임 에러가 발생할 수도 있음
- 비교 함수의 인자로 STL 혹은 클래스 객체를 전달 시 reference를 사용
    - 수행 시간의 차이가 날 수 있는 정도의 큰 차이는 아니긴함
    ```cpp
    bool cmp(const string& a, const string& b) {
        return a.back() < b.back();
    }
    ```

### BOJ 1431번: 시리얼 번호

---
## 정렬의 응용

### BOJ 11652번: 카드
```cpp
#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> V(100005);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    
    sort(V.begin(), V.begin() + N); // O(NlgN)

    int cnt = 0;
    long long mxval = -(1ll << 62) - 1;
    int mxcnt = 0;
    for (int i = 0; i < N; i++) { // O(N)
        if (i == 0 || V[i - 1] == V[i]) cnt++;
        else {
            if (cnt > mxcnt) { // `>`인 이유: 같은 크기면 작은 수를 선택(현재 오름차순 정렬 사용)
                mxcnt = cnt;
                mxval = V[i - 1];
            }
            cnt = 1;
        }
    }

    if (cnt > mxcnt) mxval = V[N - 1]; // 제일 마지막 수에 대한 처리 - 마지막 구간의 경우 갱신을 하지 않고 나오므로
    cout << mxval << '\n';

    return 0;
}

// 시간 복잡도: O(NlgN)
```
- 아이디어
    - **정렬을 하면 같은 수는 인접해진다**

- map을 사용해서 푸는 것이 더 효율적일 수 있음
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<long long, int> m;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        m[x]++; // 키가 없으면 자동으로 0을 만듦
    }

    long long mxval = 0;
    int mxcnt = 0;
    // for (auto& [val, cnt] : m) {
    //     if (cnt > mxcnt) { // 같은 결우 원래 값 유지: map은 key 기준으로 자동 정렬이 되어있음 => 작은 수부터 순회
    //         mxcnt = cnt;
    //         mxval = val;
    //     }
    // }

    for (pair<const long long, int>& p : m) {
        if (p.second > mxcnt) {
            mxcnt = p.second;
            mxval = p.first;
        }
    }

    cout << mxval << '\n';

    return 0;
}
```
