#include <iostream>
#include <vector>
#define max(a,b) a>b?a:b

using namespace std;

int max_value = -1;
int N;

void moveup(vector<vector<int>>, int);
void movedown(vector<vector<int>>, int);
void moveleft(vector<vector<int>>, int);
void moveright(vector<vector<int>>, int);

void moveup(vector<vector<int>> board, int cnt) {

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp1 = i;
			int tmp2 = i - 1;
			while (board[tmp2][j] == 0) {
				board[tmp2][j] = board[tmp1][j];
				board[tmp1][j] = 0;
				tmp1--, tmp2--;
				if (tmp2 < 0) {
					break;
				}
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i - 1][j] == board[i][j]) {
				board[i - 1][j] = board[i-1][j] + board[i-1][j];
				board[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp1 = i;
			int tmp2 = i - 1;
			while (board[tmp2][j] == 0) {
				board[tmp2][j] = board[tmp1][j];
				board[tmp1][j] = 0;
				tmp1--, tmp2--;
				if (tmp2 < 0) {
					break;
				}
			}
		}
	}

	if (cnt == 5) {
		int m_value = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				m_value = max(m_value, board[i][j]);
			}
		}
		max_value = max(max_value, m_value);
		return;
	}

	moveup(board, cnt + 1);
	movedown(board, cnt + 1);
	moveleft(board, cnt + 1);
	moveright(board, cnt + 1);
}
void movedown(vector<vector<int>> board, int cnt) {

	for (int i = N-2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			int tmp1 = i;
			int tmp2 = i + 1;
			while (board[tmp2][j] == 0) {
				board[tmp2][j] = board[tmp1][j];
				board[tmp1][j] = 0;
				tmp1++, tmp2++;
				if (tmp2 >= N) {
					break;
				}
			}
		}
	}

	for (int i = N-2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (board[i + 1][j] == board[i][j]) {
				board[i + 1][j] = board[i + 1][j] + board[i + 1][j];
				board[i][j] = 0;
			}
		}
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			int tmp1 = i;
			int tmp2 = i + 1;
			while (board[tmp2][j] == 0) {
				board[tmp2][j] = board[tmp1][j];
				board[tmp1][j] = 0;
				tmp1++, tmp2++;
				if (tmp2 >= N) {
					break;
				}
			}
		}
	}

	if (cnt == 5) {
		int m_value = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				m_value = max(m_value, board[i][j]);
			}
		}
		max_value = max(max_value, m_value);
		return;
	}

	moveup(board, cnt + 1);
	movedown(board, cnt + 1);
	moveleft(board, cnt + 1);
	moveright(board, cnt + 1);
}
void moveleft(vector<vector<int>> board, int cnt) {

	for (int j = 1; j < N ; j++) {
		for (int i = 0; i < N; i++) {
			int tmp1 = j;
			int tmp2 = j - 1;
			while (board[i][tmp2] == 0) {
				board[i][tmp2] = board[i][tmp1];
				board[i][tmp1] = 0;
				tmp1--, tmp2--;
				if (tmp2 < 0)
					break;
			}
		}
	}

	for (int j = 1; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (board[i][j-1] == board[i][j]) {
				board[i][j-1] = board[i][j-1] + board[i][j-1];
				board[i][j] = 0;
			}
		}
	}

	for (int j = 1; j < N; j++) {
		for (int i = 0; i < N; i++) {
			int tmp1 = j;
			int tmp2 = j - 1;
			while (board[i][tmp2] == 0) {
				board[i][tmp2] = board[i][tmp1];
				board[i][tmp1] = 0;
				tmp1--, tmp2--;
				if (tmp2 < 0)
					break;
			}
		}
	}

	if (cnt == 5) {
		int m_value = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				m_value = max(m_value, board[i][j]);
			}
		}
		max_value = max(max_value, m_value);
		return;
	}

	moveup(board, cnt + 1);
	movedown(board, cnt + 1);
	moveleft(board, cnt + 1);
	moveright(board, cnt + 1);
}
void moveright(vector<vector<int>> board, int cnt) {

	for (int j = N-2; j >= 0 ; j--) {
		for (int i = 0; i < N; i++) {
			int tmp1 = j;
			int tmp2 = j + 1;
			while (board[i][tmp2] == 0) {
				board[i][tmp2] = board[i][tmp1];
				board[i][tmp1] = 0;
				tmp1++, tmp2++;
				if (tmp2 >= N)
					break;
			}
		}
	}

	for (int j = N - 2; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			if (board[i][j + 1] == board[i][j]) {
				board[i][j + 1] = board[i][j + 1] + board[i][j + 1];
				board[i][j] = 0;
			}
		}
	}

	for (int j = N - 2; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			int tmp1 = j;
			int tmp2 = j + 1;
			while (board[i][tmp2] == 0) {
				board[i][tmp2] = board[i][tmp1];
				board[i][tmp1] = 0;
				tmp1++, tmp2++;
				if (tmp2 >= N)
					break;
			}
		}
	}

	if (cnt == 5) {
		int m_value = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				m_value = max(m_value, board[i][j]);
			}
		}
		max_value = max(max_value, m_value);
		return;
	}

	moveup(board, cnt + 1);
	movedown(board, cnt + 1);
	moveleft(board, cnt + 1);
	moveright(board, cnt + 1);
}

int main(void) {

	vector<vector<int>> board;
	scanf("%d", &N);

	int num;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			row.push_back(num);
		}
		board.push_back(row);
	}

	moveup(board, 1);
	movedown(board, 1);
	moveleft(board, 1);
	moveright(board, 1);
	printf("%d\n", max_value);

}
