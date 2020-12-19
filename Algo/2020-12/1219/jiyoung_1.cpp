/*
baekjoon 3024 : 마라톤 틱택토
solved by JY
DATE : 2020.12.19
구현 문제
*/
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int n;
char board[33][33];
int check[33][33];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char answer;
    bool find = false;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {  // 가로
        for (int j = 0; j < n - 2; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            if (c == board[i][j + 1]) {
                if (c == board[i][j + 2]) {
                    answer = c;
                    find = true;
                    break;
                } else {
                    j = j + 1;
                    continue;
                }
            }
        }
        if (find) break;
    }

    for (int i = 0; i < n; i++) {  // 세로
        for (int j = 0; j < n - 2; j++) {
            char c = board[j][i];
            if (c == '.') continue;
            if (c == board[j + 1][i]) {
                if (c == board[j + 2][i]) {
                    answer = c;
                    find = true;
                    break;
                } else {
                    j = j + 1;
                    continue;
                }
            }
        }
        if (find) break;
    }

    for (int i = 0; i < n - 2; i++) {  // 대각선 오른쪽
        for (int j = 0; j < n - 2; j++) {
            if (check[i][j] == 0) {
                char c = board[i][j];
                check[i][j] = 1;
                if (c == '.') continue;
                if (c == board[i + 1][j + 1]) {
                    if (c == board[i + 2][j + 2]) {
                        answer = c;
                        find = true;
                        break;
                    } else {
                        check[i + 1][j + 1] = 1;
                    }
                }
            }
        }
        if (find) break;
    }

    fill(check[0], check[33], 0);

    for (int i = 0; i < n - 2; i++) {  // 대각선 왼쪽
        for (int j = 2; j < n; j++) {
            if (check[i][j] == 0) {
                char c = board[i][j];
                check[i][j] = 1;
                if (c == '.') continue;
                if (c == board[i + 1][j - 1]) {
                    if (c == board[i + 2][j - 2]) {
                        answer = c;
                        find = true;
                        break;
                    } else {
                        check[i + 1][j - 1] = 1;
                    }
                }
            }
        }
        if (find) break;
    }

    if (find)
        cout << answer;
    else {
        cout << "ongoing";
    }

    return 0;
}
