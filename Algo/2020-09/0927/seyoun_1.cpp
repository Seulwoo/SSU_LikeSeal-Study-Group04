/*
백준 1389번 - 케빈 베이컨의 6단계 법칙
solved by seyoun
플로이드 알고리즘을 활용한 문제
*/
#include <iostream>
#define INF 1e9+7
using namespace std;
int n, m;
int rel[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			rel[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		rel[from][to] = 1;
		rel[to][from] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if(rel[s][e]> rel[s][k] + rel[k][e])
					rel[s][e] = rel[s][k] + rel[k][e];
			}
		}
	}
	int ans = -1;
	int tmp = 0;
	for (int s = 1; s <= n; s++) {
		int sum = 0;
		for (int e = 1; e <= n; e++) {
			sum += rel[s][e];
		}
		if (ans == -1 || sum < tmp) { ans = s; tmp = sum; }
	}
	cout << ans;
	return 0;
}
