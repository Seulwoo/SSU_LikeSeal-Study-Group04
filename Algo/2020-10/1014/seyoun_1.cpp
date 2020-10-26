/*
백준 - B14891 : 톱니바퀴
solved by SY
시뮬레이션
DATE : 2020.10.15
*/
#include <iostream>

using namespace std;
int map[4][2] = {6, 2, 6, 2, 6, 2, 6, 2};
int wheel[4][8];
void solve(int idx, int dir)
{
    int move[4] = {0,};
    move[idx] = dir;
    for (int i = idx - 1; i >= 0; i--)
    {
        int k = map[i][1];
        int t = map[i+1][0];
        if(wheel[i][k]==wheel[i+1][t]){
            move[i] = 0;
        }else{
            if(move[i+1]==1) move[i] = -1;
            else if(move[i+1]==-1) move[i] = 1;
            else move[i]=0;
        }
    }
    for (int i = idx + 1; i < 4; i++)
    {
        int k = map[i][0];
        int t = map[i-1][1];
        if(wheel[i][k]==wheel[i-1][t]){
            move[i] = 0;
        }else{
            if(move[i-1]==1) move[i] = -1;
            else if(move[i-1]==-1) move[i] = 1;
            else move[i]=0;
        }
    }
    for(int i =0; i<4; i++){
        if(move[i]==1){
            if(map[i][0]-1<0){map[i][0] = 7;}
            else{map[i][0]=map[i][0]-1;}

            if(map[i][1]-1<0){map[i][1] = 7;}
            else{map[i][1]=map[i][1]-1;}
        }
        if(move[i]==-1){
            if(map[i][0]+1>7){map[i][0] = 0;}
            else{map[i][0]=map[i][0]+1;}

            if(map[i][1]+1>7){map[i][1] = 0;}
            else{map[i][1]=map[i][1]+1;}
        }
    }
}
int main()
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 9; j++){
            int a = cin.get();
            if(a=='\n')continue;
            wheel[i][j] = a-'0';
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx, dir;
        cin >> idx >> dir;
        solve(idx-1, dir);
    }
    int res = 0;
    for(int i = 0; i < 4;i++){
        int t = map[i][1]-2;
        if(t<0){t=8+t;}
        if(i==0 && wheel[i][t]==1){res +=1;}
        if(i==1 && wheel[i][t]==1){res +=2;}
        if(i==2 && wheel[i][t]==1){res +=4;}
        if(i==3 && wheel[i][t]==1){res +=8;}
    }
    cout << res;
    return 0;
}
