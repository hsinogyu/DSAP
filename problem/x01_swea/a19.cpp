#include <iostream>
#include <deque>
using namespace std;

void process() {
	// 덱에 숫자 넣기
	deque<long long> DQ;
	for (int i = 0; i < 8; i++) {
		long long input;
		cin >> input;
		DQ.push_back(input);
	}

	// 생성
	bool flag = true;
	while (flag) {
		for (int i = 1; i <= 5; i++) {
			if (DQ.front() - i <= 0) {
				DQ.pop_front();
				DQ.push_back(0);
				flag = false;
				break;
			}

			long long temp = DQ.front() - i;
			DQ.pop_front();
			DQ.push_back(temp);
		}
	}

	// 출력
	while (!DQ.empty()) {
		cout << DQ.front() << ' ';
		DQ.pop_front();
	}
	cout << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 10; i++) {
		int T;
		cin >> T;
		cout << '#' << T << ' ';
		process();
	}

	return 0;
}