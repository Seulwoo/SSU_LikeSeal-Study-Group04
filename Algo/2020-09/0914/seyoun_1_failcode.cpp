/*
11052번 카드  구매하기 - 이세연 실패 코드
greedy 사용함
최적해가 전체의 최적임이 증명 되어야 하는데
이 문제는 그렇다는 보장이 없기 때문에
다른 방법으로 풀어야 한다 -> dp
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int d[1001];

bool cmp(pair<float, int> a,pair<float, int> b) {
	if (a.first < b.first) { return true; }
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<float, int> > v;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		cin >> tmp;
		d[i] = tmp;
		v.push_back(make_pair((float)((float)tmp/ (float)i),i));
	}
	sort(v.begin(), v.end(), cmp);
	int t = n;
	int res = 0;
	while (t > 0) {
		int idx = v.back().second;
		v.pop_back();
		if (t >= idx) {
			int i = t / idx;
			int j = t % idx;
			t = j;
			res += i * d[idx];
		}
	}
	cout << res;
	return 0;
}
