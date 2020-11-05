#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;



int dist[20001];
vector<pair<int, int>> nodes[300001];
int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, i;
	cin >> V >> E >> i;

	int u, v, w;
	for (int j = 0; j < E; j++) {
		cin >> u >> v >> w;
		nodes[u].push_back({ v,w });
	}

	priority_queue<pair<int, int>> PQ;
	PQ.push({ 0, i }); // cost(priority) & start
	while (!PQ.empty()) {
		int cur = PQ.top().second;
		int cost = -PQ.top().first;
		PQ.pop();

		int cur_size = nodes[cur].size();
		for (int j = 0; j < cur_size; j++) {
			int next = nodes[cur][j].first;
			int newCost = cost + nodes[cur][j].second;
			if (dist[next]==0 || dist[next] > newCost) {
				dist[next] = newCost;
				PQ.push({ -newCost, next });
			}
		}
	}

	for (int j = 1; j <= V; j++) {
		if (j == i)
			cout << 0 << endl;
		else if (dist[j])
			cout << dist[j] << endl;
		else
			cout << "INF" << endl;
	}

	return 0;
}
