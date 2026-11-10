# 정렬

## 기초 정렬

### 선택 정렬
```cpp
void sort2(int* arr, int len) {
    for (int i = n - 1; i > 0; i--) {
        int mx_idx = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[mx_idx] < arr[j]) mx_idx = j;
        }
        swap(arr[mx_idx], arr[i]);
    }
} 

void sort3(int* arr, int len) {
    for (int i = n - 1; i > 0; i++) {
        swap(*max_element(arr, arr + i + 1), arr[i]);
    }
}
```
- 가장 큰 원소를 앞에서부터 찾고, 가장 큰 원소를 가장 뒤에 배치하는 알고리즘
- O(N^2)

### 버블 정렬
```cpp
void sort(int* arr, int len) {
    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```
- 앞에서부터 크면 뒤로 보냄
- 한 사이클이 끝나면 뒤는 항상 큰 수가 옴이 보장됨
- O(N^2)

---
## Merge Sort

### 개념
- 재귀적으로 수열을 나눠 정렬한 후 합치는 정렬법
- 시간 복잡도: `O(NlgN)`

### 구현 개념
- 길이가 N / M인 정렬된 배열이 있을 때, 어떻게 효율적으로 구할 수 있을까?
- N / M 배열에서 가장 작은 원소 하나를 뽑으면 됨 = O(1)
- 비교 한 번 당 O(1)이므로 O(N+M)

### BOJ 11728번: 배열 합치기
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr1[1000001];
int arr2[1000001];
int arr3[2000002];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr1[i];
    for (int i = 0; i < M; i++) cin >> arr2[i];

    int p1 = 0, p2 = 0;
    for (int i = 0; i < N + M; i++) {
        if (p2 == M) arr3[i] = arr1[p1++];
        else if (p1 == N) arr3[i] = arr2[p2++];
        else if (arr1[p1] < arr2[p2]) arr3[i] = arr1[p1++];
        else arr3[i] = arr2[p2++];
    }

    for (int i = 0; i < N + M; i++) {
        cout << arr3[i] << '\n';
    }

    return 0;
}
```
- p1, p2가 끝까지 도달했을 때는 이후 남은 것들을 쭉 넣어줘야함

### Merge Sort 흐름
- 주어진 리스트를 2개로 나눈다
- 나눈 리스트 2개를 정렬한다
- 정렬된 두 리스트를 합친다

- 재귀적 사고
    - 길이가 1인 리스트를 정렬할 수 있다
    - 길이가 N인 두 정렬된 리스트를 합칠 수 있다
    - 길이가 N인 리스트를 정렬할 수 있으면 길이가 2N인 리스트를 정렬할 수 있다

- 시간 복잡도
    - 분할: 1, 2, 4, 8, .., 2^k = 2N -1 (O(N))
    - 병합: 각 줄에서 N번만큼 필요함, 줄은 k개가 필요함 = O(NlgN)
    - 최종: O(NlgN)

### Merge Sort 구현
```cpp
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[10000001];
int tmp[10000001];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    for (int i = st; i < en; i++) {
        if (ridx == en) tmp[i] = arr[lidx++];
        else if (lidx == mid) tmp[i] = arr[ridx++];
        else if (arr[lidx] < arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }

    for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (en == st + 1) return; // 배열의 크기가 1일때
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    merge_sort(0, n);
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}
```

### Stable Sort
- 두 원소의 값이 같을 때 가능하면 앞쪽의 원소를 넣는 정렬
- **같은 우선순위일 때, 원래의 순서를 따라가도록 하는 정렬**
- 반대는 **Unstable Sort**

---
## Quick Sort

### 직접 구현해서 사용해야할 때, 주의사항
- 그냥 사용하지마!! => merge sort를 구현해서 사용할 것

### pivot
- pivot을 하나 정함
- 왼쪽은 pivot보다 작은 수들
- 오른쪽은 pviot보다 큰 수들

### 특징
- 추가적인 공간이 필요하지 않음 - In-Place Sort
- cache hit rate가 높음

### 흐름
- 피봇을 맨 앞 원소로 잡았을 경우
- 왼쪽 l / 오른쪽 r
    - l을 피봇보다 큰 수가 나올 때까지 오른쪽으로 이동
    - r을 피봇보다 작은 수가 나올 때까지 왼쪽으로 이동
    - swap
    - 만약 l이 r보다 크면 종료
- 이후 r의 위치에 피봇을 삽입 => r은 피봇보다 작은 수를 가리키고 있으므로

### 구현
```cpp
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[10000001];

void quick_sort(int st, int en) {
    if (en <= st + 1) return;
    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;
    while (1) {
        while (l <= r && arr[l] <= pivot) l++;
        while (l <= r && arr[r] > pivot) r++;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r+1, en);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    quick_sort(0, n);
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}
```

### 시간 복잡도
- 피봇을 기준으로 접근하는 수는 O(N)
- 단계는 O(lgN)
- 총: O(NlgN)

### 단점
- 정렬이 되어있는 경우
- 최악의 경우: O(N^2)
    - 맨 앞이 피봇이고 연산하는게 매번 N이 되고
    - 단계가 N번 일어나게 됨
- 이것이 직접 구현해야할 때, 퀵 소트를 사용하지 말자!!!

---
## Merge Sort vs Quick Sort

### 정리
- 시간복잡도
    - O(NlgN)
    - O(NlgN) / O(N^2) / 단, 평균적으로는 Merge Sort보다 빠름

- 추가적으로 필요한 공간
    - O(N): tmp 배열 필요
    - O(1): In-Place Sort

- Stable Sort 여부
    - O
    - X
