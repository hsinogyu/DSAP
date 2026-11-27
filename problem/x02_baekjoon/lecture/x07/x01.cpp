#include <bits/stdc++.h>
using namespace std;

int N;
int arr[20002];
int f_idx, r_idx;

void init() {
    cin >> N;
    for (int i = 0; i < 20002; i++) {
        arr[i] = 0;
    }
    f_idx = 20002 / 2;
    r_idx = 20002 / 2 + 1;
}

void process() {
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        if (input == "push_front") {
            int num; cin >> num;
            arr[f_idx--] = num;
        }
        else if (input == "push_back") {
            int num; cin >> num;
            arr[r_idx++] = num;
        }
        else if (input =="pop_front") {
            if (f_idx == r_idx - 1) {
                cout << -1 << '\n';
            }
            else {
                cout << arr[++f_idx] << '\n';
            }
        }
        else if (input == "pop_back") {
            if (f_idx == r_idx - 1) {
                cout << -1 << '\n';
            }
            else {
                cout << arr[--r_idx] << '\n';
            }
        }
        else if (input == "size") {
            cout << r_idx - f_idx - 1 << '\n';
        }
        else if (input == "empty") {
            if (f_idx + 1 == r_idx) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (input == "front") {
            if (f_idx == r_idx - 1) {
                cout << -1 << '\n';
            }
            else {
                cout << arr[f_idx + 1] << '\n';
            }

        }
        else if (input == "back") {
            if (f_idx == r_idx - 1) {
                cout << -1 << '\n';
            }
            else {
                cout << arr[r_idx - 1] << '\n';
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