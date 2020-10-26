/*
백준 숙제 - 1726번 로봇
by 이세연
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[101][101];
int check[101][101][5];
int dir_y[5] = {0,0,0,1,-1};
int dir_x[5] = {0,1,-1,0,0};
int M, N;
int s_y,s_x,s_d;
int e_y,e_x,e_d;
int change_l(int d){ // 신기하당
	switch (d) {
		case 1:
			return 4;
		case 2:
			return 3;
		case 3:
			return 1;
		case 4:
			return 2;
		default:
			return 0;
	}
}
int change_r(int d) {
	switch (d) {
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 2;
	case 4:
		return 1;
	default:
		return 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for(int y =1;y <= M;y++){
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
		}
	}
	cin >> s_y >> s_x >> s_d;
	cin >> e_y >> e_x >> e_d;
	queue<vector<int> > q;
	q.push({ s_y,s_x,s_d }); // 오호~
	check[s_y][s_x][s_d] += 1;
	while (!q.empty()) { 
		vector<int> v = q.front();
		q.pop();
		int y = v[0], x = v[1], d = v[2];
		for (int i = 1; i <= 3; i++) { // 3번 가자!
			int n_y = y + i * dir_y[d];
			int n_x = x + i * dir_x[d];
			if (map[n_y][n_x] == 0 && n_y > 0 && n_y <= M && n_x > 0 && n_x <= N) {
				if (check[n_y][n_x][d] == 0 || check[n_y][n_x][d] > check[y][x][d] + 1) {
					check[n_y][n_x][d] = check[y][x][d] + 1;
					q.push({ n_y, n_x, d });
				}
			}
			else { break; }
		}
		int n_d = change_l(d);
		if (check[y][x][n_d] == 0 || check[y][x][n_d] > check[y][x][d] + 1) {
			check[y][x][n_d] = check[y][x][d] + 1;
			q.push({ y, x, n_d });
		}
		n_d = change_r(d);
		if (check[y][x][n_d] == 0 || check[y][x][n_d] > check[y][x][d] + 1) {
			check[y][x][n_d] = check[y][x][d] + 1;
			q.push({ y, x, n_d });
		}

	}
	cout << check[e_y][e_x][e_d] - 1;

	return 0;
}
