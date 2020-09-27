/*
백준 - 3019번 : 뱀
solved by SY
시뮬레이션 문제
*/
#include <iostream>
#include <vector>
using namespace std;
int n, k, l;
int board[101][101];
int m_y[4] = {0,1,0,-1};
int m_x[4] = {1,0,-1,0};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		board[y][x] = -1; // 사과
	}
	cin >> l;
	vector<pair<int, char>> v;
	for (int i = 0; i < l; i++) {
		int y;
		char c;
		cin >> y >> c;
		v.push_back(make_pair(y, c));
	}
	int h_y = 1, h_x = 1;//머리 위치
	int t_y = 1, t_x = 1;//꼬리 위치
	int dir = 0;//방향
	int i = 1, p = 0;//i는 시간, p는 방향 변환 확인 변수
	board[h_y][h_x] = 1; // 숫자는 뱀의 몸 번호
	for (; ; i++) {
		int y = h_y + m_y[dir], x = h_x + m_x[dir];
		if (y <= 0 || y > n || x <= 0 || x > n) { break; } // 벽부딪힘
		if (!(board[y][x] == -1 || board[y][x] == 0)) { break; } // 자기몸부딪힘?
		if (board[y][x] == -1) { // 사과냠냠
			board[y][x] = board[h_y][h_x] + 1;
			h_y = y; h_x = x;
		}
		else
		{// 꼬리가 한칸 줄어야 하는 상황
			board[y][x] = board[h_y][h_x] + 1;
			h_y = y; h_x = x;
			for (int j = 0; j < 4; j++) {
				int tmp_y = t_y + m_y[j];
				int tmp_x = t_x + m_x[j];
				if (tmp_y <= 0 || tmp_y > n || tmp_x <= 0 || tmp_x > n) { continue; }
				if (board[tmp_y][tmp_x] == board[t_y][t_x] + 1) {
					board[t_y][t_x] = 0;
					t_y = tmp_y; t_x = tmp_x; // 꼬리 갱신
					break;
				}
			}
		}
		if (p<l&&v[p].first == i) {//방향 바꾸기
			if (v[p].second == 'L') dir = (dir + 3) % 4; // 반시계 회전
			else { dir = (dir + 1) % 4; } // 시계 회전
			p++;
		}
	}
	cout << i;
	return 0;
}
