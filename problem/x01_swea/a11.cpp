#include <iostream>
#include <deque>
#include <string>
using namespace std;

int N;
char arr[100];

string process() {
	deque<char> S;

	S.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (!S.empty()) {
			if (S.back() == arr[i]) {
				S.pop_back();
			}
			else {
				S.push_back(arr[i]);
			}
		}
		else {
			S.push_back(arr[i]);
		}
	}

	string ans = "";
	while (!S.empty()) {
		ans = ans + S.front();
		S.pop_front();
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int t = 1; t <= 10; t++) {
		cin >> N;
		string input;
		cin >> input;

		for (int i = 0; i < N; i++) {
			arr[i] = input[i];
		}

		cout << '#' << t << ' ' << process() << '\n';
	}

	return 0;
}
