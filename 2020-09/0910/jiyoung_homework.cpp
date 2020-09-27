#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int b_size;
int u_size;

int cmp(string a, string b) {	// 제재 아이디인지 확인하는 함수
	if (a.size() != b.size())
		return 0;

	for (int i = 0; i < a.size(); i++) {
		if (b.at(i) == '*')
			continue;
		if (a.at(i) == b.at(i))
			continue;
		else
			return 0;
	}
	return 1;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	u_size = user_id.size();
	b_size = banned_id.size();

	vector<int> ind;	// user_id에서 b_size 갯수만큼 뽑기 위한 벡터
	for (int i = 0; i < u_size - b_size; i++) {
		ind.push_back(0);
	}
	for (int i = 0; i < b_size; i++) {
		ind.push_back(1);
	}

	do {
		vector<string> cho;	// 확인할 user_id 조합 저장
		for (int i = 0; i < u_size; i++) {
			if (ind[i] == 1)
				cho.push_back(user_id[i]);
		}
		sort(banned_id.begin(), banned_id.end());

		do {
			int i = 0;
			for (i = 0; i < cho.size(); i++) {
				if (cmp(cho[i], banned_id[i]) == 1) {	// 제재 아이디면
						continue;	// 다음 아이디도 제재 아이디인지 확인
				}
				break;	// 제재 아이디가 아님 > 다음 조합으로 가자
			}
			if (i == cho.size()) {	// cho가 제재 아이디의 조합이면 
				answer++;		// ++하고 다음 조합 확인을 위한 break;
				break;
			}
		} while (next_permutation(banned_id.begin(), banned_id.end()));
	} while (next_permutation(ind.begin(), ind.end()));

	return answer;
}
