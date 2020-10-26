#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int M = 0, N = 0, x = 1, y = 1;
		cin >> M >> N >> x >> y;
		int k = 1, m = 1, n = 1;
		int end;
		if (M % 2 == 0 && N % 2 == 0) { end = M * N / 2; }//종료조건 저장
		else { end = M * N; }
		while (true) {
			if (m == x && n == y) {
				cout << k << "\n"; break;
			}
			if (k>=end) { cout << -1 << "\n"; break; }
			if (m == x && M <= N) { 
				n += M; k += M;
				if (n > N) { n -= N; }
				continue;
			}
			if (n == y && N < M) {
				m += N; k += N;
				if (m > M) { m -= M; }
				continue;
			}
			m++;; n++; k++;
			if (m > M) { m = 1; }
			if (n > N) { n = 1; }

		}
	}
	return 0;
}
