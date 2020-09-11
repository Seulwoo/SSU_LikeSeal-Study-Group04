/*
호텔방 배정
프로그래머스 문제
by 
*/
#include <string>
#include <vector>
#include <map>

using namespace std;
long long find(map<long long , long long> &hotel, long long v) {
	if (hotel[v] == v) {
		return v;
	}
	return hotel[v] = find(hotel,hotel[v]);
}


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
	map<long long, long long> hotel;
	for (long long num : room_number) {
		if (hotel.count(num) == 0) { 
hotel.insert(make_pair(num, num));
answer.push_back(num); 
} else { 
			long long loc = find(hotel, num);
			long long tmp = loc+1;
			while (true) {
				if (hotel.count(tmp) == 0) { 
hotel.insert(make_pair(tmp, tmp)); answer.push_back(tmp); break; 
}
				tmp++;
			}
			for (long long i = loc; i < tmp; i++) {
				hotel[i] = tmp;
			}
		}
	}
    return answer;
}
