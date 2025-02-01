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
#define BIT(n, i) ((n >> i) & 1)
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

int main()
{
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    REP(i, n)
    REP(j, n)
    cin >> a[i][j];
    // dp[i][s]: 男性i人目まで全員ペアを作成したときに女性側のペアがSである組合せ
    // vector dp(n + 1, vector<mint>(1 << n, 0));
    // dp[0][0] = 1;
    // FOR(i, 1, n + 1)
    // REP(s, 1 << n)
    // {
    //     REP(j, n)
    //     if (BIT(s, j) == 1 && a[i - 1][j] == 1)
    //     {
    //         dp[i][s] += dp[i - 1][s ^ (1 << j)];
    //     }
    // }
    //
    // dp[s]: 女性側のペアがSである組合せ
    vector<mint> dp(1 << n, 0);
    dp[0] = 1;
    REP(s, 1 << n)
    {
        int i = __builtin_popcount(s);
        REP(j, n)
        if (BIT(s, j) == 1 && a[i - 1][j] == 1)
        {
            dp[s] += dp[s ^ (1 << j)];
        }
    }

    // REP(s, 1 << n)
    // {
    //     if (__builtin_popcount(s) == n)
    //         ans += dp[n][s];
    // }
    cout << dp[(1 << n) - 1].val() << '\n';

    return 0;
}