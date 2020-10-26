#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > res;
    int i = 1;
    while (true) {
        if (s.at(i) == '}' && s.at(i - 1) == '}') { break; }
        if (s.at(i) == '{') {
            i++; string tmp = ""; vector<int> a;
            while(true) {
                if (s.at(i) == '}') { a.push_back(atoi(tmp.c_str())); break; }
                if (s.at(i) == ',') { a.push_back(atoi(tmp.c_str())); tmp = ""; i++; continue; }
                tmp += s.at(i);
                i++;
            }
            res.push_back(a);
        }
        i++;
    }
    sort(res.begin(), res.end(), cmp);
    answer.push_back(res[0][0]);
    res[0][0] = 0;
    for (int i = 1; i<res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            for (int k = 0; k < answer.size(); k++) {
                if (res[i][j] == answer[k]) {
                    res[i][j] = 0;
                }
            }
            if (res[i][j] != 0) { answer.push_back(res[i][j]); continue; }
        }
    }
    return answer;
}
