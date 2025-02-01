#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    map<string, ll> m;
    string s;
    REP(i, n)
    {
        cin >> s;
        sort(s.begin(), s.end());
        m[s]++;
    }
    ll ans = 0;
    for (const auto &item : m)
    {
        ans += item.second * (item.second - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
