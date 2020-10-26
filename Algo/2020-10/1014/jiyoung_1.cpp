/*
baekjoon 15684 : 사다리 조작
solved by JY
DATE : 2020.10.15
dfs를 이용
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#define INF 1e9
#define min(a,b) a>b?b:a

using namespace std;

int n, m, h, a, b, ans = INF;
int array[33][11] = {0,};

bool is_ok() {  // 자기 자신이 되는지 확인
    for (int i = 1; i <= n; i++) {
        int col = i;
        for (int j = 1; j <= h; j++) {
            if (array[j][col - 1] == 1)  // 왼쪽으로 스윽
                --col;
            else if (array[j][col] == 1)  // 오른쪽으로 스윽
                ++col;

            if (j == h && col != i)
                return false;
        }
    }
    return true;
}

void dfs(int r, int num) {
    if (num > 3) return ;

    if (is_ok()) {  // 조작 성공 시 최솟값 갱신
        ans = min (ans, num);
        return ;
    }

    for (int i=r; i<=h; i++)
        for (int j=1; j<n; j++) {   // 세로선
            if (array[i][j] == 1) continue;     // j와 j+1 세로선 사이에 선이 있으면 continue
            if (array[i][j-1] == 1) continue;   // j-1과 j 세로선 사이에 선이 있으면 continue
            if (array[i][j+1] == 1) continue;   // j+1과 j+2 세로선 사이에 선이 있으면 continue

            array[i][j] = 1;    // j와 j+1 세로선 사이에 선을 놓기
            dfs(i, num + 1);    // dfs
            array[i][j] = 0;    // j와 j+1 세로선 사이에 선 빼기
        }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> h;

    if (m == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        array[a][b] = 1;    // a번째 줄에 세로선 b와 b+1 사이에 선이 있음
    }

    dfs(1, 0);  // 1번 째 줄부터 시작!

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
