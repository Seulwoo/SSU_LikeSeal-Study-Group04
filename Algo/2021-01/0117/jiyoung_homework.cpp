/*
baekjoon 2618 : 경찰차
solved by JY
DATE : 2020.01.17
Dynamic Programming
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n, w;
int dp[1002][1002]; // [a][b] = 경찰차1(A)이 마지막에 해결한 사건 a, 경찰차2(B)가 마지막에 해결한 사건 b일 때 최소 길이
vector<pair<int, int>> path;    // 사건 루트 저장

int solution(int a, int b) {
    if (a == w || b == w) return 0; // 마지막 사건까지 해결
    if (dp[a][b] != -1) return dp[a][b]; // 이전에 수행한 내역이 있음

    int next = max(a, b) + 1;   // 다음 사건
    int distA, distB;           // 다음 사건을 A|B가 맡을 때 이동 거리

    if (a == 0) distA = abs(1 - path[next].first) + abs(1 - path[next].second); // a가 다음사건으로 이동 시 거리
    else distA = abs(path[a].first - path[next].first) + abs(path[a].second - path[next].second);
    if (b == 0) distB = abs(n - path[next].first) + abs(n - path[next].second); // b가 다음사건으로 이동 시 거리
    else distB = abs(path[b].first - path[next].first) + abs(path[b].second - path[next].second); 

    return dp[a][b] = min(solution(next, b) + distA, solution(a, next) + distB);    // 둘 중 작은 거리로 선택
}

int route(int a, int b) {
    if (a == w || b == w) return 0;

    int next = max(a, b) + 1;
    int distA, distB;

    if (a == 0) distA = abs(1 - path[next].first) + abs(1 - path[next].second); // a가 다음사건으로 이동 시 거리
    else distA = abs(path[a].first - path[next].first) + abs(path[a].second - path[next].second);
    if (b == 0) distB = abs(n - path[next].first) + abs(n - path[next].second); // b가 다음사건으로 이동 시 거리
    else distB = abs(path[b].first - path[next].first) + abs(path[b].second - path[next].second); 

    if (solution(next, b) + distA < solution(a, next) + distB) {
        cout << 1 << '\n'; route(next, b);
    } else {
        cout << 2 << '\n'; route(a, next);
    }
    return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    path.push_back(make_pair(0, 0));
    cin >> n >> w;

    for (int i=0; i<w; i++) {
        int x, y; cin >> y >> x;
        path.push_back(make_pair(y, x));
    }
    cout << solution(0, 0) << '\n';
    route(0, 0);
	return 0;
}
