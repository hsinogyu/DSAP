#include <bits/stdc++.h>
using namespace std;

int N;

void init() {
    cin >> N;
}

void process() {
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        if (input == "push") {
            int num; cin >> num;
            Q.push(num);
        } 
        else if (input == "pop") {
            if (Q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (input == "size") {
            cout << Q.size() << '\n';
        } 
        else if (input == "empty") {
            if (Q.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        } 
        else if (input == "front") {
            if (Q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << Q.front() << '\n';
            }
        }
        else if (input == "back") {
            if (Q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << Q.back() << '\n';
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    process();

    return 0;
}


/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/