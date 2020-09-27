#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	int dp[1001] = { 0, }; 

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i/2; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	printf("%d\n", dp[n]);
}
