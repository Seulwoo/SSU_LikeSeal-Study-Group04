/*
백준 - B17822 : 원판돌리기
solved by SY
시뮬
DATE : 2020.10.16
*/
#include <iostream>
#include <vector>
using namespace std;

int N,M,T;//원판 갯수, 정수의 수, 회전 횟수
int map[51][51];
int abs(int a) {if(a<0) {a = a*(-1); return a;} return a;}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N >> M>> T;
    for(int r = 1; r <=N;r++){
        for(int c = 1; c<=M;c++){
            cin >> map[r][c];
        }
    }
    int xx,dd,kk;//배수, 방향 0: 시계 1: 반시계, 몇칸
    for(int i = 0; i<T;i++){
        cin >> xx >> dd >> kk;
        for(int j = 1; j*xx <= N;j++){
            int m_idx = j*xx; // 원판 넘버
            int tmp[51] = {0,};
            for(int k = 1; k <= M; k++){ tmp[k] = map[m_idx][k]; }
            for(int k = 1; k <= M; k++){
                if(dd == 0) {
                    kk = kk % M;
                    int t = k - kk;
                    if(t <= 0) t+=M;
                    map[m_idx][k] = tmp[t];}
                else{
                    kk = kk % M;
                    int t = k + kk;
                    if(t > M) t -= M;
                    map[m_idx][k] = tmp[t];}
            }
        }
        int visit[51][51] = {0,};
        for(int r = 1; r <=N;r++){
            for(int c = 1; c<=M;c++){
                int num = map[r][c];
                if(num == 0) continue;
                if(c-1 == 0 && map[r][M]==num) {
                    visit[r][c] = 1;
                    visit[r][M] = 1;
                }
                else if(c-1 != 0 && map[r][c-1]==num){
                    visit[r][c] = 1;
                    visit[r][c-1] = 1;
                }
                if(c+1 > M && map[r][1] == num){
                    visit[r][c] = 1;
                    visit[r][1] = 1;
                }
                else if(c+1<=M && map[r][c+1]==num){
                    visit[r][c] = 1;
                    visit[r][c+1] = 1;
                }
                if(r-1 >= 1 && map[r-1][c]==num){
                    visit[r][c] = 1;
                    visit[r-1][c] = 1;
                }
                if(r+1<=N && map[r+1][c]==num){
                    visit[r][c] = 1;
                    visit[r+1][c] = 1;
                }
            }
        }
        bool flg = true;
        double sum = 0;
        double num = 0;
        for(int r = 1; r <=N;r++){
            for(int c =1; c<=M;c++){
                if(visit[r][c]==1){
                    flg = false;
                    map[r][c] = 0;
                }else if(map[r][c]!=0){
                    sum += map[r][c];
                    ++num;
                }
            }
        }

        if(flg){
            double ss = (double)(sum/num);
            for(int r = 1; r <=N;r++){
                for(int c =1; c<=M;c++){
                    if(map[r][c]!=0){
                        if((double)map[r][c]<ss) map[r][c] += 1;
                        else if((double)map[r][c]>ss) map[r][c] -= 1;
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int r = 1; r <=N;r++){
        for(int c =1; c<=M;c++){
            sum += map[r][c];
        }
    }
    cout << sum;
    return 0;
}
