/*
백준 1238번 파티 문제
solved by 이세연
*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define max(a,b) a<b?b:a
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int V, E, X;
	cin >> V >> E >> X;
	vector<pair <int, int> > node[1001];
	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		node[from].push_back(make_pair(to, val) );
	}
	int XX[1001];//돌아가는 길 X->j
	fill(XX, XX + V + 1, INF);

	priority_queue<pair<int, int>> qu;

	qu.push({ X, 0 });
	XX[X] = 0;
	while (!qu.empty()) {
		int cost = -qu.top().second;
		int here = qu.top().first;

		qu.pop();

		for (int i = 0; i < node[here].size(); i++) {
			int next = node[here][i].first;
			int nextcost = node[here][i].second;
			if (XX[next] > XX[here] + nextcost) {
				XX[next] = XX[here] + nextcost;
				qu.push({ next,-XX[next] });
			}
		}

	}
	int m = -1;
	for (int j = 1; j < V+1; j++) {
		int YY[1001];//j->X
		fill(YY, YY + V + 1, INF);

		priority_queue<pair<int, int>> qu;

		qu.push({ j, 0 });
		YY[j] = 0;
		while (!qu.empty()) {
			int cost = -qu.top().second;
			int here = qu.top().first;

			qu.pop();

			for (int i = 0; i < node[here].size(); i++) {
				int next = node[here][i].first;
				int nextcost = node[here][i].second;
				if (YY[next] > YY[here] + nextcost) {
					YY[next] = YY[here] + nextcost;
					qu.push({ next,-YY[next] });
				}
			}

		}
		m = max(XX[j]+YY[X],m);

	}
	cout << m;

}

