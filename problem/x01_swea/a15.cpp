#include <iostream>
#include <climits>
using namespace std;

int N, M;
int n_i[20];	// 항상 작거나 같은 배열로 간주
int m_i[20];	// 항상 크거나 같은 배열로 간주

int process() {
	if (N > M) {
		int tmp = N;
		N = M;
		M = tmp;
	}
	
	int mx = INT_MIN;
	for (int i = 0; i < M - N + 1; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum = sum + (n_i[j] * m_i[i + j]);
		}
		if (mx < sum) {
			mx = sum;
		}
	}
	return mx;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			if (N > M) {
				cin >> m_i[i];
			}
			else {
				cin >> n_i[i];
			}
		}

		for (int i = 0; i < M; i++) {
			if (N > M) {
				cin >> n_i[i];
			}
			else {
				cin >> m_i[i];
			}
		}

		cout << '#' << t << ' ' << process() << '\n';
	} 

	return 0;
}
