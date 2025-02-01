#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
#define bit(n, k) ((n >> k) & 1)

int main()
{
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> vec(n);
    ll d, c, s;
    REP(i, n)
    {
        cin >> d >> c >> s;
        vec.emplace_back(d, c, s);
    }
    sort(all(vec));
    vector dp(n + 1, vector<ll>(1 << n, 0));
    dp[0][0] = 0;
    FOR(i, 1, n + 1)
    {
        REP(S, 1 << n)
        {
            REP(j, n)
            if (bit(S, j))
                continue;
            // wakarannna
        }
    }
    return 0;
}
