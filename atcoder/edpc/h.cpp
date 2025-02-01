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

constexpr int MOD = 1000000000 + 7;
int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h)
    cin >> a[i];
    vector dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    REP(i, h)
    {
        REP(j, w)
        {
            if (i < h - 1)
                if (a[i + 1][j] == '.')
                {
                    dp[i + 1][j] += dp[i][j];
                    dp[i + 1][j] %= MOD;
                }
            if (j < w - 1)
                if (a[i][j + 1] == '.')
                {
                    dp[i][j + 1] += dp[i][j];
                    dp[i][j + 1] %= MOD;
                }
        }
    }
    cout << dp[h - 1][w - 1] % MOD << '\n';

    return 0;
}