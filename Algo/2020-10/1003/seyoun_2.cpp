/*
백준 - B1865 : 
solved by SY
시뮬레이션 문제
DATE : 2020.10.02
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int A[11][11];
int map[11][11];
int mr[8] = { -1,-1,-1,0,0,1,1,1 };
int mc[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> tree[11][11];
void f1() {//봄여름
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!tree[i][j].empty()) {
				int k = 0;
				for (k = 0; k < tree[i][j].size(); k++) {
					if (map[i][j] >= tree[i][j][k]) {
						map[i][j] -= tree[i][j][k];
						tree[i][j][k] += 1;
					}
					else { break; }
				}
				int sum = 0;
				int t = tree[i][j].size() - 1;
				for (; k <= t; t--) {
					sum += (tree[i][j][t] / 2);
					tree[i][j].pop_back();
				}
				map[i][j] += sum;
			}
		}
	}
}
void f2() {//가을
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!tree[i][j].empty()) {
				int cnt = 0;
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 == 0) {
						++cnt;
					}
				}
				if (cnt > 0) {
					for (int k = 0; k < 8; k++) {
						int nr = i + mr[k];
						int nc = j + mc[k];
						if (nr<1 || nr>N || nc<1 || nc>N) continue;
						for (int g = 0; g < cnt; g++) {
							tree[nr][nc].insert(tree[nr][nc].begin(), 1);
						}
					}

				}
			}
		}
	}
}
void f3() {//겨울
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += A[i][j];
		}
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> y >> x >> z;
		tree[y][x].push_back(z);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
		}
	}
	for (int i = 0; i < K; i++) {
		f1();
		f2();
		f3();
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!tree[i][j].empty()) {
				cnt += tree[i][j].size();
			}
		}
	}
	cout << cnt;
	return 0;
}
