#include <iostream>
using namespace std;

int N;				// 찾을 회문 길이
char arr1[8][8];	// 가로 방향
char arr2[8][8];	// 세로 방향

bool is_palindrome(char* st, char* en) {
	while (st <= en) {
		if ((*st) != (*en)) {
			return false;
		}
		st++;
		en--;
	}
	return true;
}

int process() {
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8 - N + 1; j++) {
			if (is_palindrome(&arr1[i][j], &arr1[i][j + N - 1])) ans++;
			if (is_palindrome(&arr2[i][j], &arr2[i][j + N - 1])) ans++;
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int t = 1; t <= 10; t++) {
		cin >> N;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr1[i][j];
				arr2[j][i] = arr1[i][j];
			}
		}

		cout << '#' << t << ' ' << process() << '\n';
	}
	return 0;
}
