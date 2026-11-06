#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string first_input_string;
    cin >> first_input_string;

    list<char> L;
    for (int i = 0; i < first_input_string.size(); i++) {
        L.push_back(first_input_string[i]);
    }
    list<char>::iterator cursor = L.end();

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char command;
        cin >> command;

        if (command == 'L') {
            // 커서가 문장의 맨 앞이면 무시됨
            if (cursor == L.begin()) continue;

            // 커서를 왼쪽으로 한 칸 옮김
            cursor--;
        } else if (command == 'D') {
            // 커서가 문장의 맨 뒤이면 무시됨
            if (cursor == L.end()) continue;

            // 커서를 오른쪽으로 한 칸 옮김
            cursor++;
        } else if (command == 'B') {
            // 커서가 문장의 맨 앞이면 무시됨
            if (cursor == L.begin()) continue;

            // 커서 왼쪽에 있는 문자를 삭제함
            cursor = L.erase(--cursor);
        } else if (command == 'P') {
            char input;
            cin >> input;
            
            // 문자를 커서 왼쪽에 추가함
            L.insert(cursor, input);
        }
    }

    for (list<char>::iterator it = L.begin(); it != L.end(); ++it) {
        cout << *it;
    }

    return 0;
}
