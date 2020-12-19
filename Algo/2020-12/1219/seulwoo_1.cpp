#include <iostream>
#include <string>

#define endl '\n'
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;

int main(int argc, char *argv[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int i, j;
	char board[30][30];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
		getchar();
	}

	string answer = "ongoing";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-2; j++) {
			if (board[i][j] == '.')
				continue;
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
				answer = board[i][j];
			}
		}
	}
	if (answer != "ongoing") {
		cout << answer;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 2; j++) {
			if (board[j][i] == '.')
				continue;
			if (board[j][i] == board[j+1][i] && board[j][i] == board[j+2][i]) {
				answer = board[j][i];
			}
		}
	}

	if (answer != "ongoing") {
		cout << answer;
		return 0;
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < N - 2; j++) {
			if (board[i][j] == '.')
				continue;
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) {
				answer = board[i][j];
			}
		}
	}

	if (answer != "ongoing") {
		cout << answer;
		return 0;
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 2; j < N; j++) {
			if (board[i][j] == '.')
				continue;
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2]) {
				answer = board[i][j];
			}
		}
	}
	cout << answer;
	return 0;

}
