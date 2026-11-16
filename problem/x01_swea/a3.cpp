#include <iostream>
using namespace std;

int correct = 45;
int arr[9][9];

int process() {
	int nx = 0;
	int ny = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			int sum1 = 0;
			short num1 = 0x1ff;
			for (int x = i * 3; x < i * 3 + 3; x++) {
				for (int y = j * 3; y < j * 3 + 3; y++) {
					sum1 = sum1 + arr[x][y];
					num1 = num1 ^ (1 << (arr[x][y] - 1));
				}
			}
			if (sum1 != correct || num1 != 0x00) {
				return 0;
			}

			int sum2 = 0;
			short num2 = 0x1ff;
			for (int y = 0; y < 9; y++) {
				sum2 = sum2 + arr[nx][y];
				num2 = num2 ^ (1 << (arr[nx][y] - 1));
			}
			if (sum2 != correct || num2 != 0x00) {
				return 0;
			}
			nx++;

			int sum3 = 0;
			short num3 = 0x1ff;
			for (int x = 0; x < 9; x++) {
				sum3 = sum3 + arr[x][ny];
				num3 = num3 ^ (1 << (arr[x][ny] - 1));
			}
			if (sum3 != correct || num3 != 0x00) {
				return 0;
			}
			ny++;
		}
	}

	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
			}
		}

		cout << '#' << t << ' ' << process() << '\n';
	}

	return 0;
}
