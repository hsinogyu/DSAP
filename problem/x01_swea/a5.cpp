#include <iostream>
using namespace std;

int N, M;
int arr[15][15];

int dx[2][4]{
	{0, -1, 0, 1},
	{-1, -1, 1, 1}
};

int dy[2][4]{
	{ 1, 0, -1, 0 },
	{1, -1, -1, 1}
};

int process() {
	int mx = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pair<int, int> cur = { i, j };

			// + / *
			for (int shape = 0; shape < 2; shape++) {
				int sum = 0;
				sum = sum + arr[cur.first][cur.second];

				for (int dir = 0; dir < 4; dir++) {
					int n = 1;
					int nx = cur.first + dx[shape][dir];
					int ny = cur.second + dy[shape][dir];

					while (!(nx < 0 || nx >= N || ny < 0 || ny >= N || n == M)) {
						sum = sum + arr[nx][ny];

						nx = nx + dx[shape][dir];
						ny = ny + dy[shape][dir];

						n++;
					}
				}

				if (sum > mx) {
					mx = sum;
				}
			}
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
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		cout << '#' << t << ' ' << process() << '\n';
	}

	return 0;
}
