#include <iostream>
#include <algorithm>
using namespace std;
char from[1002], to[1002];
int dp[1002][1002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> from+1 >> to+1;
    int i,j;
    for(i = 1; from[i];i++){
        for(j = 1; to[j];j++){
            if(from[i]==to[j]){
                dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+1});
            }else{
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    cout << dp[i-1][j-1];
    return 0;
}
