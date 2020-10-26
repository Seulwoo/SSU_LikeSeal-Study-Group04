#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define min(a,b) a<b?a:b

using namespace std;

int move_x[4] = { 0,0,1,-1 };
int move_y[4] = { -1,1,0,0 };
int main(void) {
	int N, L, R;
	scanf("%d %d %d", &N, &L, &R);

	int A[50][50] = { {0,} };
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			scanf("%d", &A[r][c]);
		}
	}

	int answer = 0;
	bool flag = true;
	while (flag) {
		answer++;
		flag = false;
		int visit[50][50] = { {0,} };
		int group = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (visit[r][c]) {
					flag = true;
					continue;
				}
				group++;
				queue<pair<int, int>> que;
				vector<pair<int, int>> save;
				int save_sum = 0;
				que.push({ r,c });
				save.push_back({ r,c });
				save_sum += A[r][c];
				visit[r][c] = group;
				while (!que.empty()) {
					int cur_r = que.front().first, cur_c = que.front().second;
					que.pop();
					for (int d = 0; d < 4; d++) {
						int new_r = cur_r + move_x[d], new_c = cur_c + move_y[d];
						if (new_r < 0 || new_r > N - 1 || new_c < 0 || new_c > N - 1) {
							continue;
						}
						if (!visit[new_r][new_c]) {
							int diff = A[cur_r][cur_c] - A[new_r][new_c];
							if (diff < 0)
								diff *= -1;
							if (diff >= L && diff <= R) {
								visit[new_r][new_c] = group;
								save_sum += A[new_r][new_c];
								que.push({ new_r, new_c });
								save.push_back({ new_r, new_c });
							}
						}
					}
				}

				if (save.size() > 1) {
					int avg = save_sum / save.size();
					for (int s = 0; s < save.size(); s++) {
						A[save[s].first][save[s].second] = avg;
					}
				}
			}
		}
	}
	printf("%d\n", answer-1);
}
