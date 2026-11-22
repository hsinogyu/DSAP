#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C;
	cin >> A >> B >> C;
	int result = A * B * C;
	int d[10] = {};
	while (result > 0) {
		d[result % 10]++;
		result /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << d[i] << '\n';
	}
		 
	return 0;
}