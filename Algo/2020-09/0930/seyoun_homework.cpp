/*
백준 13460번 - 구슬탈출2
solved by seyoun
BFS 활용 + 시뮬레이션
*/
#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[11][11];
int m_x[4] = {1,-1,0,0};// 0:오른쪽, 1:왼쪽, 2:위, 3:아래
int m_y[4] = {0,0,-1,1};
int visit[11][11][11][11];//rx,ry,bx,by
typedef struct point {
	int r_y, r_x, b_y, b_x;
}point;

int main(void) {
	cin >> N >> M;
	int r_sx=0, r_sy=0;
	int b_sx=0, b_sy=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				b_sy = i; b_sx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R') {
				r_sy = i; r_sx = j;
				map[i][j] = '.';
			}
		}
	}

	queue<point> q; // r_y,r_x,b_y,b_x
	int count = 1;
	q.push({ r_sy,r_sx,b_sy,b_sx });
	visit[r_sx][r_sy][b_sx][b_sy] = 1;
	while (!q.empty()) {
		point tmp = q.front();
		int rx = tmp.r_x, ry = tmp.r_y;
		int bx = tmp.b_x, by = tmp.b_y;
		int count = visit[rx][ry][bx][by];
		if (count > 10) break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			bool r = false, b = false;
			rx = tmp.r_x; ry = tmp.r_y;
			bx = tmp.b_x; by = tmp.b_y;
			int r_c = 0;
			while (true) {
				rx += m_x[i]; ry += m_y[i]; r_c++;
				if (map[ry][rx] == 'O') { r = true; break; }
				else if (map[ry][rx] == '#') {
					rx -= m_x[i]; ry -= m_y[i];
					break;
				}
			}
			int b_c = 0;
			while (true) {
				bx += m_x[i]; by += m_y[i]; b_c++;
				if (map[by][bx] == 'O') { b = true; break; }
				else if (map[by][bx] == '#') {
					bx -= m_x[i]; by -= m_y[i];
					break;
				}
			}
			if (r == true && b == false) { cout << count; return 0; }
			else if (r == false && b == false) {
				if (rx == bx && ry == by) {
					if (r_c > b_c) {
						rx -= m_x[i]; ry -= m_y[i];
					}
					else {
						bx -= m_x[i]; by -= m_y[i];
					}

				}
				if (visit[rx][ry][bx][by] == 0) {
					q.push({ ry,rx,by,bx });
					visit[rx][ry][bx][by] = count + 1;
				}
			}
		}
	}
	cout << -1;
	return 0;
}
