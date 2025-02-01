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

ll d(int i, int j, vector<vector<ll>> &dp, vector<ll> &fp)
{
    // cout << i << "," << j << '\n';
    if (j - i == 1)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] >= 0)
        return dp[i][j];
    ll ans = INF;
    for (int k = j - 1; i < k; k--)
    {
        ans = min(ans, d(i, k, dp, fp) + d(k, j, dp, fp) + fp[j] - fp[i]);
    }
    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    FOR(i, 1, n + 1)
    cin >> a[i];
    // dp[i][j] : 区間(i, j]での最適な部分木構築コスト
    // fp[i][j] : 区間(i, j]での累積和
    // dp[i][j] = 0 if j == i+1
    /* dp[i][j] = min(dp[i][j-1] + dp[j-1][j] + fp[i][j-1] + fp[j-1][j],
                      dp[i][j-2] + dp[j-2][j] + fp[i][j-2] + fp[j-2][j])
    */
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    vector<ll> fp(n + 1, 0);
    FOR(i, 1, n + 1)
    fp[i] = fp[i - 1] + a[i];
    cout << d(0, n, dp, fp) << '\n';

    return 0;
}