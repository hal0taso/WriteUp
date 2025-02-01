#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
constexpr long long INF = 1000000000000LL;

int f(int i, int j, int n, int m)
{
    return i * m + j;
}

pair<int, int> r(int v, int n, int m)
{
    return {v / m, v % m};
}
int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector dp(n + 1, vector<int>(m + 1, 0));
    vector par(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m + 1)
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                par[i][j] = {i - 1, j};
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                par[i][j] = {i, j - 1};
                dp[i][j] = dp[i][j - 1];
            }

            if (s[i - 1] == t[j - 1])
            {
                if (dp[i - 1][j - 1] + 1 > dp[i][j])
                {
                    par[i][j] = {i - 1, j - 1};
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
    }
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        pair<int, int> p = par[i][j];
        i = p.first;
        j = p.second;
        if (s[i] == t[j])
        {
            ans += s[i];
        }
    }
    reverse(all(ans));
    // cout << dp[n][m] << '\n';
    cout << ans << '\n';

    return 0;
}