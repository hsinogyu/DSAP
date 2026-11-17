#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N;
// 1: N(아래로 이동) / 2: S(위로 이동)
vector<deque<int>> V(100);

int process() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		while (!V[i].empty()) {
			if (V[i].front() == 1) {		// 맨 위를 먼저 보고
				if (V[i].back() == 1) {		// 아래를 봤을 때, 1이면 
					V[i].pop_back();		// 빼주기
				}
				else {
					break;					// 위에가 1인데 아래가 2이면 교착에 빠질 것이므로 종료
				}
			}
			else {
				V[i].pop_front();
			}
		}

		// 해당 deque에서 교착 상태를 구하는 알고리즘을 구하면 됨
		// - 경계만 검사하자
		while (!V[i].empty()) {
			while (V[i].front() == 1) V[i].pop_front();

			ans++;

			while (!V[i].empty() && V[i].front() == 2) V[i].pop_front();
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int t = 1; t <= 10; t++) {
		cin >> N; // 어차피 항상 100임

		for (int i = 0; i < N; i++) {
			deque<int> dq;
			V[i] = dq;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int input;
				cin >> input;
				if (input != 0) V[j].push_back(input);
			}
		}

		cout << '#' << t << ' ' << process() << '\n';
	}
		 
	return 0;
}
