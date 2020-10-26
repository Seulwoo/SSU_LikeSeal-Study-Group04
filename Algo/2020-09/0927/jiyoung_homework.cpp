/*
baekjoon 11404 : 플로이드
solved by JY
플로이드-와샬 알고리즘 사용
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define min(a, b) a>b?b:a
#define MAX 10000000

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	int ans[102][102] = { 0, };
	int d[102][102] = { 0, };
	vector<vector<int> > v;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		vector<int> tmp;
		int a, b, c;
		cin >> a >> b >> c;
		tmp.push_back(a); tmp.push_back(b); tmp.push_back(c);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {	// 최단 거리만 저장
		if (d[v[i][0]][v[i][1]] == 0)
			d[v[i][0]][v[i][1]] = v[i][2];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				ans[i][j] = 0;
			else if (d[i][j] != 0)
				ans[i][j] = d[i][j];
			else
				ans[i][j] = MAX;
		}
	}

	for (int i = 1; i <= n; i++)	// 플로이드-와샬 알고리즘
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j] != MAX)
				cout << ans[i][j] << " ";
			else
				cout << 0 << " ";
		}
		cout << '\n';
	}

	return 0;
}
