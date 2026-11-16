#include <iostream>
using namespace std;

int N;
int arr[10][10];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void process() {
	int x = 0, y = 0, dir = 0;
	for (int num = 1; num <= N * N; num++) {
		arr[x][y] = num;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] != 0) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}

		x = nx;
		y = ny;
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
				arr[i][j] = 0;
			}
		}

		process();

		cout << '#' << t << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
