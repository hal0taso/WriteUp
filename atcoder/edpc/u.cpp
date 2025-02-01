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
constexpr long long INF = (1LL << 60);

constexpr int MOD = 1000000000 + 7;
#define BIT(n, k) ((n >> k) & 1)

ll f(ll S, vector<ll> &dp, vector<bool> &seen, vector<vector<ll>> &a)
{
    int n = a.size();
    if (seen[S])
        return dp[S];
    if (__builtin_popcount(S) <= 1)
    {
        seen[S] = true;
        return dp[S] = 0;
    }
    ll ret = 0;

    REP(i, n)
    FOR(j, i + 1, n)
    if (BIT(S, i) && BIT(S, j))
        ret += a[i][j];

    for (ll T = S; T >= 0; T--)
    {
        T &= S;
        if (T == S || T == 0)
            continue;
        ret = max(ret, f(T, dp, seen, a) + f(S ^ T, dp, seen, a));
    }
    seen[S] = true;
    return dp[S] = ret;
}

int main()
{
    int n;
    cin >> n;
    vector a(n, vector<ll>(n, 0));
    REP(i, n)
    REP(j, n)
    cin >> a[i][j];

    // dp[S]: Sの分割での最大値
    vector<ll> dp(1 << n, 0);
    vector<bool> seen(1 << n, false);
    cout << f((1 << n) - 1, dp, seen, a) << '\n';

    return 0;
}