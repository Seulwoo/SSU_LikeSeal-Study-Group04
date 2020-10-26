/*
무지의 먹방 라이브
프로그래머스 문제
by 이세연
*/

#include <string>
#include <vector>
#define ll long long 

using namespace std;

int rec(vector<pair<ll, ll> > ft, long long k) {
    int size = ft.size();
    if (size == 0) { return -1; }
    ll n = k / size; ll m = k % size;
    ll sub_sum = 0;
    vector<pair<ll, ll> > v;// value, idx
    if (k == 0) return ft[0].second;
    if (n == 0) { return ft[(m) % (size)].second; }
    for (int i = 0; i < size; i++) {
        ll res = ft[i].first - n;
        ll rmd = ft[i].second;
        if (res < 0) { sub_sum -= res; }
        if (res > 0) { v.push_back(make_pair(res, rmd)); }
    }
    return rec(v, (long long)sub_sum + m);
}
k = 2, (2,1) (1,3) (1,4)
int solution(vector<int> food_times, long long k) { 
    int answer = 0;
    int size = food_times.size();
    ll n = k / size; ll m = k % size;
    ll sub_sum = 0;
    vector<pair<ll, ll> > v;// value, idx
    if (n == 0) {
        if (m == 0)return -1;
        return m + 1;
    }
    for (int i = 0; i < size; i++) {
        int res = food_times[i] - n;
        if (res =< 0) { sub_sum -= res; }
        else { v.push_back(make_pair(res, i + 1)); } 
    }
    answer = rec(v, (long long)sub_sum + m);
    return answer;
}
