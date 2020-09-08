#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = -1;
	int c = 0;
	
	sort(dist.begin(), dist.end(), greater<int>());
	
	while (1) {
		c++;
		if (c == dist.size() + 1)
			break;

		vector<int> cho;
		for (int i = 0; i < c ; i++) {
			cho.push_back(dist[i]);
		}

		sort(cho.begin(), cho.end());

		do {
			int start = 0;
			vector<int> we = weak;
			int nu = 0;
			int flag = 1;
			for (int i = 0; i < weak.size(); i++) {
				int sum = 0;
				for (int j = start; j < we.size() - 1; j++) {
					if (sum + we[j + 1] - we[j] <= cho[nu]) {
						sum += we[j + 1] - we[j];
					}
					else {
						nu++;
						if (nu == cho.size()) {
							flag = 0;
							break;
						}
						sum = 0;
					}									   
				}
				if (flag == 1) {
					return cho.size();
				}

				we.push_back(we[start] + n);
				start++;
				nu = 0;
				flag = 1;
			}
		} while (next_permutation(cho.begin(), cho.end()));
	}

	return answer;
}
