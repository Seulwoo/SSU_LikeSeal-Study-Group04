#include <iostream>
#include <queue>
#include <set>
using namespace std;

int visit[1501][1501] = { 0, };

int main(void) {
	int A, B, C, sum;
	scanf("%d %d %d", &A, &B, &C);
	sum = A + B + C;

	queue<vector<int>> bfs_queue;

	bfs_queue.push({ A, B, C });
	visit[A][B] = 1;
	while (!bfs_queue.empty()) {
		vector<int> cur = bfs_queue.front();
		bfs_queue.pop();

		A = cur[0], B = cur[1], C = cur[2];

		if (A == B && B == C) {
			printf("1");
			return 0;
		}

		if (A > B) {
			int X = B + B, Y = A - B;
			if (!visit[Y][X]) {
				bfs_queue.push({ Y, X, C });
				visit[Y][X] = 1;
			}
		}
		else if (A < B) {
			int X = A + A, Y = B - A;
			if (!visit[X][Y]) {
				bfs_queue.push({ X, Y, C });
				visit[X][Y] = 1;
			}

		}

		if (B > C) {
			int X = C + C, Y = B - C;
			if (!visit[A][Y]) {
				bfs_queue.push({ A, Y, X });
				visit[A][Y] = 1;
			}
		}
		else if (B < C) {
			int X = B + B, Y = C - B;
			if (!visit[A][X]) {
				bfs_queue.push({ A, X, Y });
				visit[A][X] = 1;
			}
		}

		if (A > C) {
			int X = C + C, Y = A - C;
			if (!visit[Y][B]) {
				bfs_queue.push({ Y, B, X });
				visit[Y][B] = 1;
			}
		}
		else if (A < C) {
			int X = A + A, Y = C - A;
			if (!visit[X][B]) {
				bfs_queue.push({ X, B, Y });
				visit[X][B] = 1;
			}
		}

	}
	printf("0");
	return 0;
}
