#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

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
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = 1000000000000LL;

constexpr int MOD = 1000000000 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    FOR(i, 1, n + 1)
    cin >> a[i];

    // dp[i][j] := a_iまででjの選び方
    // dp[i+1][j] = dp[i][j - a[i]] + dp[i][j - a[i] + 1] + ... + dp[i][j]
    vector dp(n + 1, vector<mint>(k + 1, 1));
    // REP(j, k + 1)
    // dp[0][j] = 1;

    FOR(i, 1, n + 1)
    {
        // dp[i][0] = 1;
        FOR(j, 1, k + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] > 0)
                dp[i][j] -= dp[i - 1][j - a[i] - 1];
        }
        FOR(j, 1, k + 1)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }
    if (k > 0)
        cout << (dp[n][k] - dp[n][k - 1]).val() << '\n';
    else
        cout << 1 << '\n';

    return 0;
}