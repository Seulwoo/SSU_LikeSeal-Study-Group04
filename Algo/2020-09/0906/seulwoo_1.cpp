#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comparebysecond(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first >= b.first;
    return a.second >= b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    vector<pair<int, int>> food_stack;
    for (int i = 0; i < food_times.size(); i++) {
        food_stack.push_back(make_pair(i+1, food_times[i]));
    }
    
    sort(food_stack.begin(), food_stack.end(), comparebysecond);
    int cycle = 0, min_cycle = food_stack.back().second, stack_size = food_stack.size();
    
    while (k >= (long long)((min_cycle - cycle) * stack_size)) {
        k = k - (long long)((min_cycle - cycle) * stack_size);
        cycle = min_cycle;
        while ((!food_stack.empty()) && food_stack.back().second == min_cycle) {
            food_stack.pop_back();
        }
        min_cycle = food_stack.back().second;
        stack_size = food_stack.size();
        if (stack_size <= 0)
            break;
    }
    sort (food_stack.begin(), food_stack.end());
    if (stack_size > 0)
        answer = food_stack[k%stack_size].first;
    return answer;
}
