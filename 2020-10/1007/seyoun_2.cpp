/*
백준 - B12886 : 돌 그룹
solved by SY
BFS, 잘 모르겠어서 블로그를 참고 했습니다.
나중에 한번 더 풀어 볼것!
DATE : 2020.10.08
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<long long> s;
bool flg;
void solve(long long A, long long B, long long C){
    if(A==B && B==C ){
        flg = true;
        return;
    }
    vector<long long> v = {A,B,C};
    sort(v.begin(),v.end());
    long long tmp = v[2]*2000+v[0];
    if(s.find(tmp)!=s.end()){return;}
    s.insert(tmp);
    for(int i =0; i<3;i++){
        for(int j = 0;j<3;j++){
            if(v[i]>v[j]){
                int mn = v[j];
                v[j] +=mn;
                v[i] -=mn;
                solve(v[0],v[1],v[2]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long A,B,C;
    cin >> A>>B>>C;
    if((A+B+C)%3!=0) {cout << 0; return 0;}
    solve(A,B,C);
    if(flg) cout << 1;
    else cout << 0;
    return 0;
}
