/*
baekjoon 2151 : 거울 설치
solved by JY
DATE : 2020.10.09
bfs를 이용하여 풀이
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define min(a, b) a > b ? b : a
#define INF 1e9

using namespace std;

int N;
char H[52][52] = {0,};
int mirror[52][52][4] = {0,};	// mirror[A][B][C] = D : (A,B)에서 빛이 C방향으로 진행 시 지금까지 설치한 문의 갯수는 D개
int dx[4] = {0, 0, -1, 1};  // 상,하,좌,우
int dy[4] = {-1, 1, 0, 0};
int s_x, s_y, e_x, e_y;
int ans = INF;

int change_dir(int dir, int shape) {
    if (shape == 0) {  // / 거울일 경우 방향 전환
        if (dir == 0) return 3;
        if (dir == 1) return 2;
        if (dir == 2) return 1;
        if (dir == 3) return 0;
    }
    if (shape == 1) {  // \ 거울일 경우 방향 전환
        if (dir == 0) return 2;
        if (dir == 1) return 3;
        if (dir == 2) return 0;
        if (dir == 3) return 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool flag = true;

    cin >> N;

    for (int i = 0; i < N; i++) {	// 입력
        for (int j = 0; j < N; j++) {
            cin >> H[i][j];
            if (H[i][j] == '#' && flag) {
                s_x = j;
                s_y = i;
                flag = false;
            } else if (H[i][j] == '#' && !flag) {
                e_x = j;
                e_y = i;
            }
        }
    }

    fill(mirror[0][0], mirror[52][0], INF);	// mirror 배열 INF로 초기화

    queue<vector<int> > q;

    for (int i = 0; i < 4; i++) {	// 시작문 상,하,좌,우 
        q.push({s_y, s_x, i});
		mirror[s_y][s_x][i] = 0;
    }

    while (!q.empty()) {	// bfs
        int y = q.front().at(0);	// 현재칸
        int x = q.front().at(1);
        int dir = q.front().at(2);
        q.pop();

        int c_y = y + dy[dir];		// 다음칸
        int c_x = x + dx[dir];
        int c_dir = 0;

        if (c_x < 0 || c_x >= N || c_y < 0 || c_y >= N) continue;
        if (H[c_y][c_x] == '*') continue;
        if (H[c_y][c_x] == '.') {
            if (mirror[c_y][c_x][dir] > mirror[y][x][dir]) {
                mirror[c_y][c_x][dir] = mirror[y][x][dir];
                q.push({c_y, c_x, dir});
            }
        } else if (H[c_y][c_x] == '!') {
            if (mirror[c_y][c_x][dir] > mirror[y][x][dir]) {  // 거울 없음
                if (mirror[c_y][c_x][dir] > mirror[y][x][dir]) {
                    mirror[c_y][c_x][dir] = mirror[y][x][dir];
                    q.push({c_y, c_x, dir});
                }
                c_dir = change_dir(dir, 0);  // / 거울일 경우 전환된 방향
                if (mirror[c_y][c_x][c_dir] > mirror[y][x][dir] + 1) {
                    mirror[c_y][c_x][c_dir] = mirror[y][x][dir] + 1;
                    q.push({c_y, c_x, c_dir});
                }
                c_dir = change_dir(dir, 1);  // \ 거울일 경우 전환된 방향
                if (mirror[c_y][c_x][c_dir] > mirror[y][x][dir] + 1) {
                    mirror[c_y][c_x][c_dir] = mirror[y][x][dir] + 1;
                    q.push({c_y, c_x, c_dir});
                }
            }
        } else if (H[c_y][c_x] == '#' && c_y == e_y && c_x == e_x) {  // 도착 문일 경우
            if (mirror[c_y][c_x][dir] > mirror[y][x][dir]) {
                mirror[c_y][c_x][dir] = mirror[y][x][dir];
                ans = min(ans, mirror[c_y][c_x][dir]);	// 설치할 거울 최소 개수 확인
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
