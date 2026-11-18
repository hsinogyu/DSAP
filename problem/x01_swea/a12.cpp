#include <iostream>
#include <string>
using namespace std;

int N;			// 길이
int arr[50];	// 원래 상태 비트를 담을 배열

int process() {
	int ans = 0;
	bool flag = false;  
	for (int i = 0; i < N; i++) {
		if (flag == false && arr[i] == 1) {
			flag = true;
			ans++;
		}

		if (flag == true && arr[i] == 0) {
			flag = false;
			ans++;
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string input;
		cin >> input;

		N = input.size();
		for (int i = 0; i < N; i++) {
			arr[i] = input[i] - '0';
		}

		cout << '#' << t << ' ' << process() << '\n';
	}
 
	return 0;
}

// 풀이: 앞에서부터 보면서 현재 값과 다르면 그 위치부터 끝까지 뒤집는다.
//       (앞을 확정해도 이후 연산이 앞쪽을 건드리지 않으므로 앞에서부터 처리)
// 최적성: 연산 1번에 인접 비트가 달라지는 경계는 최대 1개만 생긴다.
//         초기(전부 0)의 경계 수는 0이므로, 목표의 경계 수 k만큼은 반드시 필요하다.