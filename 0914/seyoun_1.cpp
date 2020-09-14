/*
11052번: 카드 구매하기
이세연 코드
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<float, int> > v;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		cin >> dp[i];
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];
	return 0;
}
