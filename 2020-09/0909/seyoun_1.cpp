/*카카오 외벽 찾기 문제
level 3단계*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = -1;
	sort(dist.begin(), dist.end());
	for (int i = 0; i < weak.size(); i++) {
		if (i != 0) {
			int tmp = weak[0] + n;
			int j;
			for (j = 1; j < weak.size(); j++) {
				weak[j - 1] = weak[j];
			}
			weak[j - 1] = tmp;
		}

		while (true) {
			int w_num = 0;
			int f;
			for (f = 0; f < dist.size(); f++) {
				int tmp = weak[w_num] + dist[f];
				while (true) {
					if (tmp >= weak[w_num]) { w_num++; }
					else { break; }
					if (w_num == weak.size()) { break; }
				}
				if (w_num == weak.size()) { break; }
			}
			if (w_num == weak.size()) {
				if (answer == -1 || f + 1 < answer) {
					answer = f + 1;
				}
			}
			if (!next_permutation(dist.begin(), dist.end())) { break; }
		}

	}

	return answer;
}
