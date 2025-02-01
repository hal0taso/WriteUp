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

int main()
{
    int N, W;
    cin >> N >> W;
    vector<ll> w(N + 1), v(N + 1);
    REP(i, N)
    cin >> w[i + 1] >> v[i + 1];
    // dp[i][j] iまでの荷物を使って価値v以上とできる重さの最小値
    ll M = 100000LL;
    vector dp(N + 1, vector<ll>(M + 1, INF));
    dp[0][0] = 0;

    FOR(i, 1, N + 1)
    {
        FOR(j, 0, M + 1)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            if (j - v[i] >= 0)
                dp[i][j] = min(dp[i - 1][j - v[i]] + w[i], dp[i][j]);
        }
    }
    ll ans = 0;
    for (int i = M; i >= 0; i--)
        if (dp[N][i] <= W)
        {
            ans = i;
            break;
        }
    cout << ans << '\n';

    return 0;
}