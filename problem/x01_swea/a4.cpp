#include <iostream>
using namespace std;

int N, K, ANS;
int arr[15][15];

void process() {
	int rowLen = 0;
	int colLen = 0;

	for (int i = 0; i < N; i++) {
		int rowLen = 0;
		int colLen = 0;

		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				rowLen++;
			}
			else {
				if (rowLen == K) {
					ANS++;
				}
				rowLen = 0;
			}

			if (arr[j][i] == 1) {
				colLen++;
			}
			else {
				if (colLen == K) {
					ANS++;
				}
				colLen = 0;
			}
		}

		// 마지막 처리(마지막도 1인 경우 증가만 하고 검사를 하지 못함)
		if (rowLen == K) ANS++;
		if (colLen == K) ANS++;
	}

}
 
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		ANS = 0;
		process();

		cout << '#' << t << ' ' << ANS << '\n';
	}

	return 0;
}
