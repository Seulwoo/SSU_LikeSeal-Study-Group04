#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main(void) {

	bool gear[4][8] = { 0, }; // 세연이의 wheel
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char state;
			scanf("%c", &state);
			gear[i][j] = state - '0';
		}
		getchar();
	}
	pair<int, int> chain[4]; // 세연이의 map
	for (int i = 0; i < 4; i++) {
		chain[i] = { 2,6 };
	}

	int K;
	scanf("%d", &K);

	while (K-- > 0) {
		int idx, dir;
		scanf("%d %d", &idx, &dir);
		idx--;
		dir *= -1;

		queue<pair<int, pair<int, int>>> check;
		check.push({ 0,{idx, dir} });
		while (!check.empty()) {
			int flag = check.front().first;
			int index = check.front().second.first;
			int direction = check.front().second.second;
			check.pop();

			if (flag != 1 && index > 0) {
				if (gear[index][chain[index].second] != gear[index - 1][chain[index - 1].first]) {
					check.push({ -1, {index - 1, direction*-1} }); // 회전하라고 방향이랑 같이 큐에 넣어줌
				}
			}
			if (flag != -1 && index < 3) {
				if (gear[index][chain[index].first] != gear[index + 1][chain[index + 1].second]) {
					check.push({ 1, {index + 1, direction*-1} }); // 회전하라고 방향이랑 같이 큐에 넣어줌
				}
			}

			chain[index].first += direction; // 회전
			if (chain[index].first >= 8)
				chain[index].first -= 8;
			else if (chain[index].first < 0)
				chain[index].first += 8;

			chain[index].second += direction;
			if (chain[index].second >= 8)
				chain[index].second -= 8;
			else if (chain[index].second < 0)
				chain[index].second += 8;
		}

	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int top = chain[i].first - 2;
		if (top < 0)
			top += 8;
		if (gear[i][top] == 1) {
			sum += pow(2, i);
		}
	}
	printf("%d\n", sum);
}
