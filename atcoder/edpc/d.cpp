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
constexpr long long INF = LLONG_MAX;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<ll> w(N + 1), v(N + 1);
    REP(i, N)
    cin >> w[i + 1] >> v[i + 1];
    // dp[i][j] iまでの荷物を使って重さj以下となるような最適値
    vector dp(N + 1, vector<ll>(W + 1, 0));
    FOR(i, 1, N + 1)
    {
        FOR(j, 1, W + 1)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j]);
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[N][W] << '\n';

    return 0;
}