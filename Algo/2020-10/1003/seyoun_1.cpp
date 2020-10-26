/*
백준 - B16236 : 아기상어
solved by SY
BFS + 시뮬레이션 문제
문제를 제대로 읽지 않아서 30분 허비함. 반성할 것..
DATE : 2020.10.02
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int map[21][21];
int ty, tx;
int my[4] = { 1,-1,0,0 };
int mx[4] = { 0,0,1,-1 };
int _size = 2;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) { return true; }
	if (a.first == b.first) {
		if (a.second < b.second) { return true; }
	}
	return false;
}

int find(int sy, int sx) {
	int ch[21][21] = { 0, };
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	ch[sy][sx] = 1;
	int min = -1;
	vector<pair<int, int>> v;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (ch[ny][nx] == 0) {
				if (map[ny][nx] != 0 && map[ny][nx] < _size) {
					int tmp = ch[y][x] + 1;
					if (min == -1 || min >= tmp) {
						v.push_back(make_pair(ny, nx));
						ch[ny][nx] = tmp;
						min = tmp;
					}
				}
				else if(map[ny][nx]==0||map[ny][nx]==_size){
					q.push(make_pair(ny, nx));
					ch[ny][nx] = ch[y][x] + 1;
				}
			}
		}
	}
	if (!v.empty()) {
		sort(v.begin(), v.end(),cmp);
		ty = v[0].first;
		tx = v[0].second;
		return min;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int sx = -1, sy = -1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				sy = y; sx = x;
				map[y][x] = 0;
			}
		}
	}
	ty = sy, tx = sx;
	int res=0, tmp=0;
	while (true) {
		int t = find(ty, tx);
		if (t == -1) { break; }
		res += (t-1);
		map[ty][tx] = 0;
		if (++tmp == _size) { ++_size; tmp = 0; }
	}
	cout << res;
	return 0;
}
