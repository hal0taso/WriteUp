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
    int n;
    cin >> n;
    vector<double> p(n + 1);
    FOR(i, 1, n + 1)
    cin >> p[i];

    // dp[i][j] i枚目まで投げたときにj枚表になっている確率
    vector dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1.;
    FOR(i, 1, n + 1)
    dp[0][i] = 0.0;
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, n + 1)
        {
            dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
        REP(j, n + 1)
        {
            dp[i][j] += dp[i - 1][j] * (1. - p[i]);
        }
    }
    double ans = 0.0;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}