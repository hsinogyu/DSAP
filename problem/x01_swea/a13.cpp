#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
int arr[50][50];
int vis[50][50];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int process() {
	queue<pair<int, int>> Q;
	vis[N / 2][N / 2] = 0;
	Q.push({ N / 2, N / 2 });
	int sum = arr[N / 2][N / 2];

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();

		if (vis[cur.first][cur.second] == N / 2) {
			return sum;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny] > -1) continue;

			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
			sum = sum + arr[nx][ny];
		}
	}

	return sum;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			string input;
			cin >> input;

			for (int j = 0; j < N; j++) {
				arr[i][j] = input[j] - '0';
				vis[i][j] = -1;
			}
		}

		cout << '#' << t << ' ' << process() << '\n';
	}

	return 0;
}
