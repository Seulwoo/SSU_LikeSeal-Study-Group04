#include <iostream>
#include <vector>

using namespace std;
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,-1,1 };

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	pair<int, int> board[20][20]; // 냄새가 남는 배열
	pair<int, int> sharks[401]; // 상어 위치
	int shark_dir[401]; // 상어의 방향 배열
	int props[400][5][4]; // 방향들 우선순위 상어번호-현재방향-우선순위
	int shark_cnt = M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			scanf("%d", &tmp);
			board[i][j] = { tmp, 0 };
			if (board[i][j].first > 0) {
				sharks[board[i][j].first] = { i, j };
				board[i][j].second = K;
			}
		}
	}
	
	for (int i = 1; i <= M; i++) {
		scanf("%d", &shark_dir[i]);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int t = 0; t < 4; t++) {
				scanf("%d", &props[i][j][t]);
			}
		}
	}

	int sec = 0; // 시작
	while (shark_cnt > 1) { // 상어가 1마리남을때까지
		if (sec++ >= 1000) { // 1000초이상이면 -1
			sec = -1;
			break;
		}

		for (int i = 1; i <= M; i++) { // 상어 1번부터 ~
			if (sharks[i].first == -1) // 좌표에 -1이 저장되어잇으면 먹힌 상어라 패스
				continue;
			int cur_dir = shark_dir[i]; // 상어가 바라보는 방향
			bool empty_flag=false;
			for (int j = 0; j < 4; j++) {
				int new_dir = props[i][cur_dir][j];
				int new_i = sharks[i].first + move_x[new_dir-1], new_j = sharks[i].second + move_y[new_dir-1];
				if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1) {
					continue;
				}
				if (board[new_i][new_j].second <= 0) { // 빈칸으로 이동
					empty_flag = true;
					//printf("%d : %d %d move %d %d dir %d\n", i, sharks[i].first, sharks[i].second, new_i, new_j, new_dir);
					sharks[i] = { new_i, new_j };
					shark_dir[i] = new_dir;
					break;
				}
			}

			if (!empty_flag) { // 주위에 냄새업는 칸이 없으면
				for (int j = 0; j < 4; j++) {
					int new_dir = props[i][cur_dir][j];
					int new_i = sharks[i].first + move_x[new_dir - 1], new_j = sharks[i].second + move_y[new_dir - 1];
					if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > N - 1) {
						continue;
					}
					if (board[new_i][new_j].first == i) { // 내냄새가 담긴 칸으로 이동
						//printf("%d : %d %d move %d %d dir %d\n", i, sharks[i].first, sharks[i].second, new_i, new_j, new_dir);
						sharks[i] = { new_i, new_j };
						shark_dir[i] = new_dir;
						break;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) { // 냄새 지속시간 빼주기
			for (int j = 0; j < N; j++) {
				if (board[i][j].second > 0) {
					board[i][j].second--;
				}
			}
		}
		for (int i = 1; i <= M; i++) { //저장된 상어 위치를 바탕으로 K시간의 냄새 추가
			if (sharks[i].first != -1) {
				int cur_i = sharks[i].first, cur_j = sharks[i].second;
				if (board[cur_i][cur_j].second == K) { // 숫자 작은 상어랑 겹치면
					sharks[i] = { -1, -1 }; // 먹힘 표시
					shark_cnt--; // 상어 수 감소
				}
				else {
					board[cur_i][cur_j] = { i, K }; // 냄새 업데이트				}
			}
		}

	}
	printf("%d\n", sec);
}
