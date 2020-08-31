#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second >= b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> numbers;
    
    for (int i = 2; i < s.length(); i++) {
        int num = 0;
        while (s.at(i) >= '0' && s.at(i) <= '9') {
            num *= 10;
            num += s.at(i) - '0';
            i++;
        }
        if (num != 0) {
            if (numbers.count(num) == 0) {
                numbers[num] = 1;
            }
            else {
                numbers[num] = numbers[num]+1;
            }
            i--;
        }
    }
    
    vector<pair<int, int>> num_vec;
    for (map<int, int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        num_vec.push_back(make_pair(it->first, it->second));
    }
    sort(num_vec.begin(), num_vec.end(), compare);
    for (vector<pair<int, int>>::iterator it = num_vec.begin(); it != num_vec.end(); it++) {
        answer.push_back(it->first);
    }
    return answer;
}
