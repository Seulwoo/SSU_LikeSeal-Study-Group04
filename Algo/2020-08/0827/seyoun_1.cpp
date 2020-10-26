#include <string>
#include <vector>

using namespace std;
bool check(string s){
    vector<char> v;
    for (int i = 0; i < s.size(); i++) {
        if (v.empty()) {
            if(s[i] == '(') v.push_back(s[i]);
            else { return false; }
        }
        else {
            if (v.back() != s[i]) { v.pop_back(); }
             else { v.push_back(s[i]); }
        }
    }
    if (v.empty()) { return true; }
    return false;
}

string solution(string p) {
    int l = 0, r = 0;
    string answer = "";
    string u = "";
    string v = "";
    if (p == "") return "";
    for (int i = 0; i < p.size(); i++) {
        if (p.at(i) == '(' )l++;
        else { r++; }
        if (l == r) { 
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break; }
    }
    if (check(u)) { answer += u; return  answer += solution(v); }
    else {
        string ans = "(";
        for (int i = 1; i < u.size()-1; i++) {
            if (u.at(i) == '(') { ans += ")"; }
            if (u.at(i) == ')') { ans += "("; }
        }
        ans += ")";
        ans += solution(v);
        return ans;
    }
}
