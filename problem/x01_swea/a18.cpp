#include <iostream>
using namespace std;

int N, L, ans;
int t_arr[20];	// 점수
int k_arr[20];	// 칼로리

void process(int k, int score, int kal) {
	if (kal > L) {
		return;
	}

	if (k == N) {
		if (ans < score) {
			ans = score;
		}
		return;
	}

	// 넣은 경우
	process(k + 1, score + t_arr[k], kal + k_arr[k]);

	// 넣지 않은 경우
	process(k + 1, score, kal);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> L;
		ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> t_arr[i];
			cin >> k_arr[i];
		}
		process(0, 0, 0);
		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}
