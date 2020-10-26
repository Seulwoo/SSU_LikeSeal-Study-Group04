#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int move_i[4] = { -1,1,0,0 };
int move_j[4] = { 0,0,-1,1 };

int main() {
	int N, M, fuel;
	scanf("%d %d %d", &N, &M, &fuel);

	int map[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int taxi_i, taxi_j;
	scanf("%d %d", &taxi_i, &taxi_j);
	taxi_i--, taxi_j--;
	pair<int, int> dest_info[401]; // 이거는 도착지 위치가 들어있는 배열
	int depart_i, depart_j, dest_i, dest_j;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &depart_i, &depart_j, &dest_i, &dest_j);
		map[depart_i-1][depart_j-1] = (i + 2);
		dest_info[i + 2] = { dest_i - 1, dest_j - 1 };
	}

	while (M > 0) { // M을 줄여가면서 몇명 남았는지 체크
		queue <pair<int, pair<int, int>>> check;
		int visit[20][20] = { 0, };
		int min_dist = 401, min_customer = 401, min_i, min_j;

		check.push({ 0, {taxi_i, taxi_j} });
		visit[taxi_i][taxi_j] = 1;
		while (!check.empty()) { // bfs로 최단거리에 있는 사람 구하기
			int cur_dist = check.front().first;
			int cur_i = check.front().second.first, cur_j = check.front().second.second;
			check.pop();

			if (map[cur_i][cur_j] > 1) {
				if (min_dist > cur_dist) {
					min_dist = cur_dist;
					min_customer = map[cur_i][cur_j];
					min_i = cur_i, min_j = cur_j;
				}
				else if (min_dist == cur_dist) { // 최단거리가 여러명이면 그중에서 행번호, 열번호가 작은 순으로 우선순위
					if (min_i > cur_i) {
						min_customer = map[cur_i][cur_j];
						min_i = cur_i, min_j = cur_j;
					}
					else if (min_i == cur_i && min_j > cur_j) {
						min_customer = map[cur_i][cur_j];
						min_i = cur_i, min_j = cur_j;
					}
				}
				else {
					break;
				}
			}

			for (int d = 0; d < 4; d++) { // visit랑 queue로 bfs
				int new_i = cur_i + move_i[d], new_j = cur_j + move_j[d];
				if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1)
					continue;
				if (visit[new_i][new_j] == 0 && map[new_i][new_j] != 1) {
					check.push({ cur_dist + 1, {new_i, new_j} });
					visit[new_i][new_j] = 1;
				}
			}
		}
		if (min_dist > 400) { // 승객한테 갈 방법이 업으면 -1 출력
			fuel = -1;
			break;
		}

		fuel = fuel - min_dist;
		if (fuel < 0) { // 승객한테 가는동안 연료 다 쓰면 -1
			fuel = -1;
			break;
		}

		queue <pair<int, pair<int, int>>> check_back; // 위에서 택시->사람이었다면,, 이번에는 똑같이 사람->목적지를 bfs로 찾아서 거리를구한다. 그런데 큐랑 배열 초기화하기 귀찮아서 새로 선언해서씀
		int visit_back[20][20] = { 0, };
		check_back.push({ 0, {min_i, min_j} });
		visit_back[min_i][min_j] = 1;
		int last_dist = -1, last_i = -1, last_j = -1;
		while (!check_back.empty()) { // bfs
			int cur_dist = check_back.front().first;
			int cur_i = check_back.front().second.first, cur_j = check_back.front().second.second;
			check_back.pop();

			if (dest_info[min_customer].first == cur_i && dest_info[min_customer].second == cur_j) {
				last_dist = cur_dist, last_i = cur_i, last_j = cur_j;
				break;
			}

			for (int d = 0; d < 4; d++) {
				int new_i = cur_i + move_i[d], new_j = cur_j + move_j[d];
				if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1)
					continue;
				if (visit_back[new_i][new_j] == 0 && map[new_i][new_j] != 1) {
					check_back.push({ cur_dist + 1, {new_i, new_j} });
					visit_back[new_i][new_j] = 1;
				}
			}
		}

		if (last_dist == -1) { // 도착지가 막혀서 갈 방법이 업으면 -1
			fuel = -1;
			break;
		}
		
		fuel = fuel - last_dist;
		if (fuel < 0) { // 도착지 가는동안 연료 다쓰면 -1
			fuel = -1;
			break;
		}
		else { // 아니면 연료 추가
			fuel = fuel + (last_dist * 2);
			map[min_i][min_j] = 0; // 승객이 사라짐을 표시
			M--;
			taxi_i = last_i, taxi_j = last_j; // 택시의 위치를 도착지로 초기화!!
		}
	}
	printf("%d\n", fuel);
}
