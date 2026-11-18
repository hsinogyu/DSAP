#include <iostream>
#include <climits>
using namespace std;

int N;
int arr[1000005];

long long process() {
	long long mx = LLONG_MIN;
	long long profit = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] > mx) {
			mx = arr[i];
		}
		else {
			profit = profit + (mx - arr[i]);
		}
	}

	return profit;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		cout << '#' << t << ' ' << process() << '\n';
	}

	return 0;
}