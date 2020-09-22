/*
백준 1767번 : N-Rook II
dynamic programming > top-down 방식
행 기준으로 0개, 1개, 2개인 경우로 생각
2개인 경우는 행에 2개, 열에 2개로 나눠서 생각
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long dp[105][105][105];

long f(int y, int x, int k) {
	if (y < 0 || x < 0 || k < 0)
		return 0;

	if (k == 0)
		return 1;

	if (dp[y][x][k] != -1) {
		return dp[y][x][k];
	}

	long ans = 0;

	ans += f(y - 1, x, k);
	ans += x * f(y - 1, x - 1, k - 1);
	ans += x * (x - 1) / 2 * f(y - 1, x - 2, k - 2);
	ans += (y - 1) * x * f(y - 2, x - 1, k - 2);

	ans %= 1000001;
	return dp[y][x][k] = ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	fill(dp[0][0], dp[104][0], -1);

	cout << f(n, m, k) << '\n';

	return 0;
}