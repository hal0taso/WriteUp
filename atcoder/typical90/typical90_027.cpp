#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <cstdint>
#include <limits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

bool valid(string s)
{
    if (s.size() < 1 || s.size() > 15)
    {
        return false;
    }
    REP(i, s.size())
    {
        if (s[i] - 'a' >= 0 && s[i] - 'a' < 26)
            continue;
        else if (s[i] - '0' >= 0 && s[i] - '0' < 10)
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    string s;
    set<string> user;
    FOR(i, 1, n + 1)
    {
        cin >> s;
        if (valid(s) && user.find(s) == user.end())
        {
            user.insert(s);
            cout << i << endl;
        }
    }
    return 0;
}