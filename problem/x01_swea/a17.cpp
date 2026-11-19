#include <iostream>
#include <string>
using namespace std;

int H, W, N;
int i_x, i_y;
char board[20][20];
char command[100];

int dir;
int dx[4] = {-1, 1, 0, 0}; // 위 / 아래 / 좌 / 우
int dy[4] = {0, 0, -1, 1};

bool check_bound(int nx, int ny) {
	if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
		return true;
	}
	return false;
}

void process_u() {
	// 전차가 바라보는 방향 변경
	board[i_x][i_y] = '^';

	// 다음 칸 구하기
	int nx = i_x + dx[dir];
	int ny = i_y + dy[dir];
	if (check_bound(nx, ny)) {
		return;
	}

	// 칸이 평지라면 그 칸으로 이동
	if (board[nx][ny] == '.') {
		board[nx][ny] = board[i_x][i_y];
		board[i_x][i_y] = '.';
		i_x = nx;
		i_y = ny;
	}
}

void process_d() {
	// 전차가 바라보는 방향 변경
	board[i_x][i_y] = 'v';

	// 다음 칸 구하기
	int nx = i_x + dx[dir];
	int ny = i_y + dy[dir];
	if (check_bound(nx, ny)) {
		return;
	}

	// 칸이 평지라면 그 칸으로 이동
	if (board[nx][ny] == '.') {
		board[nx][ny] = board[i_x][i_y];
		board[i_x][i_y] = '.';
		i_x = nx;
		i_y = ny;
	}
}

void process_l() {
	// 전차가 바라보는 방향 변경
	board[i_x][i_y] = '<';

	// 다음 칸 구하기
	int nx = i_x + dx[dir];
	int ny = i_y + dy[dir];
	if (check_bound(nx, ny)) {
		return;
	}

	// 칸이 평지라면 그 칸으로 이동
	if (board[nx][ny] == '.') {
		board[nx][ny] = board[i_x][i_y];
		board[i_x][i_y] = '.';
		i_x = nx;
		i_y = ny;
	}
}

void process_r() {
	// 전차가 바라보는 방향 변경
	board[i_x][i_y] = '>';

	// 다음 칸 구하기
	int nx = i_x + dx[dir];
	int ny = i_y + dy[dir];
	if (check_bound(nx, ny)) {
		return;
	}

	// 칸이 평지라면 그 칸으로 이동
	if (board[nx][ny] == '.') {
		board[nx][ny] = board[i_x][i_y];
		board[i_x][i_y] = '.';
		i_x = nx;
		i_y = ny;
	}
}

void process_s() {
	// 방향은 dir로 이미 정해지기 때문에 따로 확인할 필요가 없을 것 같음

	int nx = i_x + dx[dir];
	int ny = i_y + dy[dir];
	while (!(check_bound(nx, ny) || board[nx][ny] == '*' || board[nx][ny] == '#')) {
		nx = nx + dx[dir];
		ny = ny + dy[dir];
	}

	// 맵 밖으로 나가거나 강철 벽일 경우 아무것도 하지 않음
	if (check_bound(nx, ny) || board[nx][ny] == '#') {
		return;
	}

	if (board[nx][ny] == '*') {
		board[nx][ny] = '.'; // 평지로 변경
	}
}

void print_board() {
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cout << board[h][w];
		}
		cout << '\n';
	}
}

void process() {
	for (int i = 0; i < N; i++) {
		char input = command[i];

		switch (input) {
		case 'U':
			dir = 0;
			process_u();
			break;
		case 'D':
			dir = 1;
			process_d();
			break;
		case 'L':
			dir = 2;
			process_l();
			break;
		case 'R':
			dir = 3;
			process_r();
			break;
		case 'S':
			process_s();
			break;
		default:
			break;
		}
	}

	// 게임 맵 상태 출력
	print_board();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> H >> W;
		for (int h = 0; h < H; h++) {
			string input;
			cin >> input;
			for (int w = 0; w < W; w++) {
				board[h][w] = input[w];
				if (input[w] == '<' || input[w] == '^' || input[w] == '>' || input[w] == 'v') {
					i_x = h;
					i_y = w;
				}
				if (input[w] == '^') dir = 0;
				else if (input[w] == 'v') dir = 1;
				else if (input[w] == '<') dir = 2;
				else if (input[w] == '>') dir = 3;
			}
		}

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> command[i];
		}

		cout << '#' << t << ' ';
		process();
	}

	return 0;
}