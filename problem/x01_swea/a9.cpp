#include <iostream>
using namespace std;

char arr1[100][100];
char arr2[100][100];

bool is_palindrome(char* st, char* en) {
	while (st < en) {
		if ((*st) != (*en)) {
			return false;
		}

		st++;
		en--;
	}
	return true;
}

int process() {
	for (int n = 100; n > 0; n--) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100 - n + 1; j++) {
				if (is_palindrome(&arr1[i][j], &arr1[i][j + n - 1])) {
					return n;
				}
				if (is_palindrome(&arr2[i][j], &arr2[i][j + n - 1])) {
					return n;
				}
			}
		}
	}

	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int t = 1; t <= 10; t++) {
		int T;
		cin >> T;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr1[i][j];
				arr2[j][i] = arr1[i][j];
			}
		}

		cout << '#' << T << ' ' << process()  << '\n';
	}

	return 0;
}