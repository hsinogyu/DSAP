#include <iostream>
using namespace std;

int N;
int arr[1000];

int process() {
	int sum = 0;
	for (int i = 2; i < N - 2; i++) {
		// 좌 검사
		int left_mx = 0;
		bool left = false;
		if (arr[i - 2] < arr[i] && arr[i - 1] < arr[i]) {
			left_mx = (arr[i - 2] < arr[i - 1]) ? arr[i - 1] : arr[i - 2];
			left = true;
		}

		// 우 검사
		int right_mx = 0;
		bool right = false;
		if (arr[i + 2] < arr[i] && arr[i + 1] < arr[i]) {
			right_mx = (arr[i + 2] < arr[i + 1]) ? arr[i + 1] : arr[i + 2];
			right = true;
		}

		// 둘 다 통과면 조망권 확보 후 계산
		if (left && right) {
			int mx = left_mx < right_mx ? right_mx : left_mx;
			sum = sum + (arr[i] - mx);
		}
	}
	return sum;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int t = 1; t <= 10; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		cout << '#' << t << ' ' << process() << '\n';
	}

	return 0;
}

// 더 좋은 방법
// - 주변 4개의 칸의 최댓값이 나보다 작은가를 구하면 됨
//      - 그렇다는 건 나보다 다 작다는 것이기 때문에 조망권 자체는 확보된 수준
// - 그리고 그 최댓값을 가지고 조망권 계산
