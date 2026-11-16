#include <iostream>
using namespace std;

int N;
int arr[7][7];

void process() {
	for (int i = 0; i < N; i++) {
		for (int x = N - 1; x >= 0; x--) {
			cout << arr[x][i];
		}
		cout << ' ';

		for (int y = N - 1; y >= 0; y--) {
			cout << arr[N - 1 - i][y];
		}
		cout << ' ';

		for (int x = 0; x < N; x++) {
			cout << arr[x][N - 1 - i];
		}
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		cout << '#' << t << '\n';
		process();
	}

	return 0;
}
