# 재귀

## 알고리즘 설명

### 정의
- 하나의 함수에서 자기 자신을 다시 호출해 작업을 수행하는 알고리즘

### 재귀 예시
```cpp
// n부터 1까지 출력하는 함수
void func1(int n) {
    if (n == 0) return;
    cout << n << ' ';
    func1(n - 1);
}

// 1부터 n까지 합을 구하는 함수
void func2(int n) {
    if (n == 0) return 0;
    return n + func2(n - 1);
}
```
- 주의: 단순히 동작이 아니라, 이 코드가 왜 정상적으로 동작하는지 제대로 이해할 필요가 있음

### 수학적 귀납법 - 도미노
- 제일 앞의 도미노를 쓰러뜨리면 모든 도미노가 쓰러짐
- 근데 왜 모든 도미노가 쓰러지는지를 설명할 수 있어야함
- 설명 1
    - 1번 도미노가 쓰러지면 2번 도미노가 쓰러지고, 2번 도미노가 쓰러지면 3번 도미노가 쓰러지고, ...
- 설명 2
    - 1번 도미노가 쓰러진다
    - k번 도미노가 쓰러지면 k+1번 도미노도 쓰러진다
    - 위 두개의 명제가 참이므로 모든 도미노가 쓰러진다고 할 수 있음

> 절차지향적인 사고를 탈피해야함

### 절차지향적 사고 - n부터 1까지 출력하는 함수
```cpp
void func1(int n) {
    if (n == 0) return;
    cout << n << ' ';
    func1(n - 1);
}
```
- 절차지향적 사고 - func1(3)
    - 3 출력
    - func1(2) 호출
    - 2 출력
    - func1(1) 호출
    - 1 출력
    - func1(0) 호출
    - if (n == 0) return => func1(0) 함수 종료
    - func1(1) 함수 종료
    - func1(2) 함수 종료
    - func1(3) 함수 종료
    - 결과: 3, 2, 1 출력

- 귀납적 사고 - func1(3)
    - func1(1)을 출력한다
    - func1(k)가 k, k-1, k-2, ..., 1을 출력하면, func(k+1)은 k+1, k, k-1, ..., 1을 출력한다
        - k+1를 호출하면 k+1을 출력하고, func1(k)가 호출되고, func1(k)는 k, k-1, ..., 1을 출력한다
    - 위 두문장이 참이므로 func1(n)이 n부터 1까지 출력한다는 사실을 알 수 있음

### 재귀 함수의 조건 - 매우 중요
- 특정 입력에 대해서는 자기 자신을 호출하지 않고 종료되어야 함(Base Condition)
- 모든 입력은 Base Condition으로 수렴해야함
```cpp
if (n == 0) return; // base condition
func1(n - 1); // base condition으로 수렴
```

### 재귀에 대한 정보 1
- 함수의 인자로 어떤 것을 받고 어디까지 계산한 후 자기 자신에게 넘겨줄지 명확하게 정해야 함
- 모든 재귀 함수는 반복문만으로 동일한 동작을 하는 함수를 만들 수 있음
- 재귀는 반복문으로 구현했을 때에 비해 코드가 간결하지만 메모리/시간에서는 손해를 봄

### 재귀에 대한 정보 2
- 한 함수가 자기 자신을 여러 번 호출하게 되면 비효율적일 수 있음
```cpp
int fibo(int n) {
    if (n <= 1) return 1;
    return fibo(n-1) + fibo(n-2);
}
```
- 상식적으로 피보나치를 계산하기 위해 필요한 횟수는 n번째를 구할 때 N정도의 시간이 필요함
- 근데 재귀 함수의 시간 복잡도는 O(1.618^n)
    - fibo(5)
        - fibo(4) + fibo(3)
            - fibo(3) + fibo(2)
                - fibo(2) + fibo(1)
                    - fibo(1) + fibo(0)
                - fibo(1) + fibo(0)
            - fibo(2) + fibo(1)
                - fibo(1) + fibo(0)
    - 이미 계산할 걸 또 게산하는 일이 빈번함을 알 수 있음
    - 나중에 다이나믹 프로그래밍이라는 방법으로 O(N)에 해결할 수 있음

### 재귀에 대한 정보 3
- 재귀 함수가 자기 자신을 부를 때 스택 영역에 계속 누적됨
- 문제를 풀 때 메모리 제한이 있음
    - Stack이 1MB로 제한되어 있는 경우가 있을 수 있음(전체 메모리 제한 512MB)
    - **반복문 사용**

---
## 연습 문제 1 - 거듭제곱

### a^b mod m
> a의 b승을 m으로 나눈 나머지를 구하여라
```cpp
int func1(int a, int b, int m) {
    int val = 1;
    while (b--) val *= a;
    return val % m;
}
```
- int overflow가 발생하는 코드
- 중간 중간 m으로 나눠서 나머지만 챙겨가면 됨 
```cpp
using ll = long long
ll func1(ll a, ll b, ll m) {
    ll val = 1;
    while (b--) val = val * a % m;
    return val;
}
```
```cpp
#include <bits/stdc++.h>
using namespace std;

long long A, B, M;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> M;
    long long remain = 1;
    for (long long i = 0; i < B; i++) {
        remain = (remain * A) % M;
    }

    cout << remain << '\n';

    return 0;
}
```
- 시간 복잡도: O(b)

### BOJ 1629번: 곱셈
```cpp
#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;
    int val = 1;
    while (B--) val = val * A % C;
    cout << val << '\n';

    return 0;
}
```
- 시간 초과
    - O(b)인데, B가 21억이여서 시간 초과가 발생함

```cpp
#include <bits/stdc++.h>
using namespace std;

long long A, B, C;

long long func(long long A, long long B, long long C) {
    if (B == 0) return 1 % C; // B가 만약 0을 넣을 수 있다면
    if (B == 1) return A % C;

    long long half = func(A, B/2, C);
    long long result = (half * half) % C;

    if (B % 2 == 0) {
        return result;
    } else {
        return (result * (A % C)) % C;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;
    cout << func(A, B, C) << '\n';

    return 0;
}
```
- 사고 과정
    - 1승을 계산할 수 있다
    - k승을 계산했으면 2k승과 2k+1승도 O(1)에 계산할 수 있다

- 추가적으로 필요한 성질
    - 2^k * 2^k = 2^(2k)

- 시간 복잡도: O(logB)

---
## 연습 문제 2 - 하노이 탑

### BOJ 11729번: 하노이 탑 이동 순서
- 사고 과정
    - n-1개의 원판을 기둥 1에서 기둥 2로 옮긴다
    - n번 원판을 기둥 1에서 기둥 3으로 옮긴다
    - n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다

- 귀납적 사고
    - 원판이 1개일 때 원판을 내가 원하는 곳으로 옮길 수 있다
    - 원판이 k개일 때 옮길 수 있으면 원판이 k+1개일 때에도 옮길 수 있다
    - **원판이 n-1개일 때 옮길 수 있으면 원판이 n개일 때에도 옮길 수 있다**

- 함수의 정의
    - `void func(n)`: 원판 n개를 기둥 1에서 기둥 3으로 옮기는 방법을 출력하는 함수
        - 잘못된 이유: 원판 n-1개는 기둥 1에서 기둥 2로 옮겨야함
    - `void func(int a, int b, n)`: n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수 

- base condition
    - `n == 1`일 때 cout << a << ' ' << b << '\n';
    
- 재귀식
    - a도 b도 아닌 기둥의 번호는 6 - a - b
    - n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다
    - n번 원판을 기둥 a에서 기둥 b로 옮긴다
    - n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다

```cpp
#include <bits/stdc++.h>
using namespace std;

int N;

void func(int n, int src, int dst) {
    if (n == 1) {
        cout << src << ' ' << dst << '\n';
        return;
    }

    func(n - 1, src, 6 - src - dst);
    cout << src << ' ' << dst << '\n';
    func(n - 1, 6 - src - dst, dst);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cout << (1 << N) - 1 << '\n';
    func(N, 1, 3);

    return 0;
}
```

---
## 연습 문제 3 - Z

### BOJ 1074번: Z
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, R, C;

int func(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1);

    if (r < half && c < half) {
        return func(n-1, r, c);
    } else if (r < half && c >= half) {
        return half * half + func(n-1, r, c - half);
    } else if (r >= half && c < half) {
        return 2 * half * half + func(n-1, r - half, c);
    } else {
        return 3 * half * half + func(n-1, r - half, c - half);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> C;
    cout << func(N, R, C) << '\n';

    return 0;
}
```
- 사고 과정
    - 전체적인 그림으로 보기
    - 1 2 3 4의 칸이 있고, 2번칸을 방문하기 위해서는 1번칸을 무조건 방문, 3번칸을 방문하기 위해서는 1번, 2번칸을 무조건 방문
    - 그림을 키워도 동일함
    - 특정 사분면의 특정 좌표를 탐색하기 위해서 이전 사분면의 모든 칸을 거쳐야됨
    - 한 사분면의 크기: 내가 지금 방문해야하는 사각형의 1/4

- 함수의 정의
    - int func(int n, int r, int c): 2^n * 2^n 배열에서 (r, c)를 방문하는 순서를 반환하는 함수

- base condition
    - n == 0일 때 return 0;

- 재귀식
    - (r, c) 1번 사각형일 때 return func(n-1, r, c);
    - (r, c) 2번 사각형일 때 return half * half + func(n-1, r, c-half)
    - (r, c) 3번 사각형일 때 return 2 * half * half + func(n-1, r-half, c)
    - (r, c) 4번 사각형일 때 return 3 * half * half + func(n-1, r-half, c-half)
    - 여기서 half는 n-1
