#include <iostream>
#include <vector>

using namespace std;
int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> A_vec;
	for (int i = 0; i < N; i++) {
		int A;
		scanf("%d", &A);
		A_vec.push_back(A);
	}

	int B, C;
	scanf("%d %d", &B, &C);

	long long answer = A_vec.size();
	while (!A_vec.empty()) {
		int A = A_vec.back();
		A_vec.pop_back();
		A -= B;
		if (A > 0) {
			answer += (A / C);
			if (A%C)answer++;
		}
	}
	printf("%lld", answer);
}
