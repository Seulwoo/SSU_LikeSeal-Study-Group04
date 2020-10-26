#include <iostream>
#include <vector>
#define INF 999999999

using namespace std;

int main(void) {
	int TC;
	scanf("%d", &TC); // 테스트케이스의 개수

	for (int i = 0; i < TC; i++) {
		int N, M, W;
		scanf("%d %d %d", &N, &M, &W); // 노드의 수, 도로의 수, 웜홀의 수
		vector<pair<int, int>> edges[501];

		int S, E, T;
		for (int j = 0; j < M; j++) { // 도로 정보
			scanf("%d %d %d", &S, &E, &T); // Start, End, Time
			edges[S].push_back({ E, T }); // 도로는 방향이 있음 /방향이 없어서 두번 하는 거 아냐?
			edges[E].push_back({ S, T }); //아!!!! 반대로 이해했다
		}

		for (int j = 0; j < W; j++) { // 웜홀 정보
			scanf("%d %d %d", &S, &E, &T); // 웜홀은 방향이 업슴
			edges[S].push_back({ E, -T }); // 줄어드는 시간 추가
		}

		int dist[501];
		fill(dist, dist + 500, INF); // 최대값으로 초기화
		dist[1] = 0; // 출발 시간이 0

		bool isUpdated = false;
		for (int j = 1; j <= N; j++) {
			for (int t = 1; t <= N; t++) {
				int edge_size = edges[t].size(); // 노드당 도로 개수
				for (int edge = 0; edge < edge_size; edge++) {
					int from = t; // 출발지
					int to = edges[t][edge].first; // 목적지
					int weight = edges[t][edge].second; // 걸리는 시간
					if (dist[to] > dist[from] + weight) { // 최단시간 업뎃
						dist[to] = dist[from] + weight;
						if (j == N) isUpdated = true; // 출발 시간에 0보다 작은 숫자가 들어온 경우//이게 왜 출발시간에 0보다 작은 값이 들어온거졍?!
				}
				}
			}
		}
		if (isUpdated) { // 출발위치로 돌아온 경우
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}
