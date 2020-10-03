#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int move_x[8] = { 0,0,1,1,1,-1,-1,-1 };
int move_y[8] = { 1,-1,0,1,-1,0,1,-1 };

int main(void) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	int field[10][10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			field[i][j] = 5;
		}
	}

	int food[10][10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &food[i][j]);
		}
	}

	vector<int> tree[10][10];
	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		tree[x-1][y-1].push_back(z);
	}

	while (K-- > 0) { // 년수만큼
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tree[i][j].size() > 1) {
					sort(tree[i][j].begin(), tree[i][j].end());
				}
			}
		}

		for (int i = 0; i < N; i++) { // 봄
			for (int j = 0; j < N; j++) {
				int tree_cnt = tree[i][j].size();
				for (int t = 0; t < tree_cnt; t++) {
					if (field[i][j] >= tree[i][j][t]) {
						field[i][j] -= tree[i][j][t];
						tree[i][j][t]++;
					}
					else {
						tree[i][j][t] *= -1;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) { // 여름
			for (int j = 0; j < N; j++) {
				while (!tree[i][j].empty()) {
					int last_tree = tree[i][j].back();
					if (last_tree >= 0) {
						break;
					}
					else {
						tree[i][j].pop_back();
						field[i][j] += (int)(last_tree * -1 / 2);
					}
				}
			}
		}

		for (int i = 0; i < N; i++) { // 가을
			for (int j = 0; j < N; j++) {
				int tree_cnt = tree[i][j].size();
				for (int t = 0; t < tree_cnt; t++) {
					if (tree[i][j][t] % 5 == 0) {
						for (int m = 0; m < 8; m++) {
							int new_i = i + move_x[m], new_j = j + move_y[m];
							if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1)
								continue;
							tree[new_i][new_j].push_back(1);
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++) { // 겨울
			for (int j = 0; j < N; j++) {
				field[i][j] += food[i][j];
			}
		}
	}

	int tree_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tree_cnt += tree[i][j].size();
		}
	}
	printf("%d\n", tree_cnt);
}
