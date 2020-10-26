#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int tablesize = timetable.size();
    vector<pair<int, int>> table;
    
    for (int i = 0; i < tablesize; i++) {
        string time = timetable.at(i);
        int hour = ((int)time.at(0) - '0')*10 + ((int)time.at(1) - '0');
        int min = ((int)time.at(3) - '0')*10 + ((int)time.at(4) - '0');
        table.push_back(make_pair(hour, min));
    }
    sort(table.begin(), table.end());
    
    int p_idx = 0;
    pair<int, int> cur = {9, 0};
    while (n > 1) {
        for (int i = 0; i < m; i++) {
            if (p_idx >= tablesize)
                break;
            if (table[p_idx] <= cur) {
                p_idx++;
            }
            else {
                break;
            }
        }
        n--;
        cur.second += t;
        while (cur.second >= 60) {
            cur.first++; cur.second-=60;
        }
    }
    
    while (m > 0) {
        if (p_idx >= tablesize)
            break;
        if (table[p_idx] <= cur) {
            p_idx++;
        }
        else {
            break;
        }
        m--;
    }
    if (m == 0) {
        int hour = table[p_idx-1].first;
        int min = table[p_idx-1].second;
        min--;
        if (min < 0) {
            hour--; min=59;
        }
        answer += to_string(hour/10);
        answer += to_string(hour%10);
        answer += ":";
        answer += to_string(min/10);
        answer += to_string(min%10);
    }
    else {
        int hour = cur.first;
        int min = cur.second;
        answer += to_string(hour/10);
        answer += to_string(hour%10);
        answer += ":";
        answer += to_string(min/10);
        answer += to_string(min%10);
    }
    
    return answer;
}
