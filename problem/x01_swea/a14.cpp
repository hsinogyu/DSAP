#include <iostream>
using namespace std;

int N;
int min_location;
int how_many;

int my_abs(int num) {
	if (num < 0) {
		return -1 * num;
	}
	else {
		return num;
	}
}

void process() {
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		int location = my_abs(input);
		if (min_location > location) {
			min_location = location;
			how_many = 1;
		}
		else if (min_location == location) {
			how_many++;
		}
		else {
			continue;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		min_location = 100005;
		how_many = 0;
		process();
		cout << '#' << t << ' ' << min_location << ' ' << how_many << '\n';
		
	}

	return 0;
}
