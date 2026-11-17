#include <iostream>
#include <algorithm>
using namespace std;

int N;			// 덤프 횟수
int arr[100];	// 가로 기준 각 블럭의 높이

int find_mxidx() {
	int mxidx = 0;
	for (int i = 0; i < 100; i++) {
		if (arr[mxidx] < arr[i]) {
			mxidx = i;
		}
	}
	return mxidx;
}

int find_mnidx() {
	int mnidx = 0;
	for (int i = 0; i < 100; i++) {
		if (arr[mnidx] > arr[i]) {
			mnidx = i;
		}
	}
	return mnidx;
}

int process() {
	for (int i = 0; i < N; i++) {
		int mxidx = find_mxidx();
		int mnidx = find_mnidx();
		// int* mxp = max_element(arr, arr+100);
		// int* mnp = min_element(arr, arr+100);

		// if (*mxp - *mnp <= 1) break;

		// (*mxp)--;
		// (*mnp)++;

		if (arr[mxidx] - arr[mnidx] <= 1) {
			break; // 평탄화 완료
		}

		arr[mxidx]--;
		arr[mnidx]++;
	}

	int mxidx = find_mxidx();
	int mnidx = find_mnidx();

	return arr[mxidx] - arr[mnidx];
}
 
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int t = 1; t <= 10; t++) {
		cin >> N;
		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
		}

		cout << '#' << t << ' ' << process() << '\n';
	}

	return 0;
}