/*
백준 - B14395 : 4연산
solved by SY
DATE : 2020.10.07
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<string> res;
int mn = -1;
bool cmp(string a, string b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() == b.size())
        if (a < b)
        return true;
    return false;
}
void solv(string str, ll s, ll t)
{
    if (s == t)
    {
        if (mn == -1 || mn >= str.size())
        {
            res.push_back(str);
            mn = str.size();
        }
        return;
    }
    if (s > t)
        return;
    if (s != 1)
        solv(str + '*', s * s, t);
    solv(str + '+', s + s, t);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << "0";
        return 0;
    }

    solv("/", 1, t);
    solv("", s, t);

    if (res.empty())
    {
        cout << -1;
        return 0;
    }
    sort(res.begin(), res.end(), cmp);

    cout << res[0];
    return 0;
}
