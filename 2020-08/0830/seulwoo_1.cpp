#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int lcm(int M, int N) {
	int a = M, b = N;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return M * N / a;
}

int solution(int M, int N, int x, int y) {
	int cur = x;
	int max = lcm(M, N); // 최소공배수가 최대값
	
	if (y == N)
		y = 0;
	while (cur <= max) {
		if (cur%N == y) {
			return cur;
		}
		cur += M; // x값을 기준으로, y값도 일치하는지 확인
	}
	return -1;
}

int main(void) {
	int n, M, N, x, y;
	vector<int> answer;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d %d", &M, &N, &x, &y);
		answer.push_back(solution(M, N, x, y)); // 입출력용 벡터
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d\n", answer[i]);
	}
	while (1);
}
