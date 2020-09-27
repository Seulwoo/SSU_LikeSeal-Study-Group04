/*
1238 - 파티
priority_queue 사용
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define INF 1e9
#define max(a,b) (a>b?a:b)

using namespace std;

vector<vector<int> > co(1001);
int time[1001][1001] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x;
	int check[1001];
	int answer = 0;

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		co[a].push_back(b);
		time[a][b] = t;
	}

	for (int i = 1; i <= n; i++) {
		check[i] = INF;
	}

	priority_queue <int> s;
	s.push(x);
	check[x] = 0;

	while (!s.empty()) {
		int f = s.top();
		s.pop();

		for (int i = 0; i < co[f].size(); i++) {
			if (check[f] + time[f][co[f][i]] < check[co[f][i]]) {
				check[co[f][i]] = check[f] + time[f][co[f][i]];

				s.push(co[f][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;

		priority_queue <int> s;
		int d[1001];

		for (int j = 1; j <= n; j++) {
			d[j] = INF;
		}

		s.push(i);
		d[i] = 0;

		while (!s.empty()) {
			int f = s.top();
			s.pop();

			for (int i = 0; i < co[f].size(); i++) {
				if (d[f] + time[f][co[f][i]] < d[co[f][i]]) {
					d[co[f][i]] = d[f] + time[f][co[f][i]];

					s.push(co[f][i]);
				}
			}
		}

		check[i] += d[x];
		answer = max(check[i], answer);
	}

	cout << answer;

	return 0;
}
