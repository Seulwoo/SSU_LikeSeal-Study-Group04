// 오랜 만에 풀어서, ROW와 COL, X,Y가 뒤죽 박죽으로 적혀 있는 문제이다.

#include <iostream>
using namespace std;
int Rmov[4] = {1,1,0,-1};
int Cmov[4] = {0,1,1,1};
char board[31][31];
int N;
bool check(int X, int Y, int cnt, char ch, int idx){
    if(X>=N||Y>=N||X<0||Y<0){
        return false;
    }
    if(board[X][Y] == '.'){return false;}
    if(board[X][Y] != ch){return false;}
    if(cnt == 2 ){ return true;}
    return check(X+Rmov[idx], Y+Cmov[idx],cnt+1,ch,idx);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> board[i];
    }
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            for(int idx = 0; idx < 4; idx++){
                if(board[r][c] == '.'){continue;}
                if(check(r+Rmov[idx],c+Cmov[idx],1,board[r][c],idx)){
                    cout << board[r][c];
                    return 0;
                }
            }
        }
    }
    cout << "ongoing";
    return 0;
}
