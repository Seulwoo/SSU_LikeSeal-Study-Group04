#include <string>
#include <vector>

using namespace std;

bool isRightString(string p) { // 올바른 문자열인지 true false로 체크
    int left_cnt = 0;
    int p_length = p.length();
    for (int i = 0; i < p_length; i++) {
        if (p.at(i) == '(') {
            left_cnt++;
        }
        else {
            if (left_cnt > 0) {
                left_cnt--;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int balanceSlice(string p) { // 더이상 분리할 수 없는 균형잡힌 괄호 문자열의 인덱스 반환
    int left_cnt = 0;
    int p_length = p.length();
    for (int i = 0; i < p_length; i++) {
        if (p.at(i) == '(') {
            left_cnt++;
        }
        else {
            left_cnt--;
        }
        if (left_cnt == 0)
            return i;
    }
}

string bracket_reverse(string p) { // 첫번째 문자와 마지막 문자를 제거하고 괄호 방향 뒤집는 함수
    string tmp = "";
    int p_length = p.length();
    for (int i = 1; i < p_length-1; i++) {
        if (p.at(i) == '(') {
            tmp += ')';
        }
        else {
            tmp += '(';
        }
    }
    return tmp;
}

string check_recursive(string p) {
    int slice_index = balanceSlice(p);
    string u, v, tmp;
    if (p.length() < 1) { // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
        return p;
    }
    u = p.substr(0, slice_index+1); // 2. 문자열을 두 "균형잡힌 괄호 문자열"로 분리
    v = p.substr(slice_index+1);
    
    if (isRightString(u)) { // 3. 문자열 u가 "올바른 괄호 문자열"이라면
        return u+check_recursive(v); // 3-1. 문자열 v를 재귀 수행하고 u에 이어 붙인 후 반환
    }
    else { // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면
        tmp = "("; // 4-1. 빈 문자열에 첫 번째 문자로 (
        tmp += check_recursive(v); // 4-2. 문자열 v에 대해 재귀 수행한 결과를 append
        tmp += ")"; // 4-3. )를 다시 붙임
        tmp += bracket_reverse(u); // 4-4. u의 첫번째와 마지막 문자제거하고 괄호 방향 뒤집어서 append
        return tmp; // 4-5. 생성된 문자열을 반환
    }
}

string solution(string p) {
    string answer = "";
    answer = check_recursive(p); // 시작 >,<
    return answer;
}
