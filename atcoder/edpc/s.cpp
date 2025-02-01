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

int main()
{
    string k;
    int d;
    cin >> k >> d;
    int n = k.size();
    vector<int> a(n);
    REP(i, n)
    a[i] = k[i] - '0';
    // reverse(all(a));
    // dp[i][j][l]: 上位l桁を決めたときにmod d = jとなる組合せ数 (i = 0なら上位l桁までkに張り付いている, o.w., そうでない (i.e., 次の桁を自由に選べる))
    vector dp(2, vector(d, vector<mint>(n + 1, 0)));
    dp[0][0][0] = 1;
    // dp[0][0][0] = 1;
    FOR(l, 1, n + 1)
    {
        REP(dig, 10)
        {
            REP(j, d)
            {
                dp[1][(j + dig) % d][l] += dp[1][j][l - 1];
            }
        }
        REP(dig, a[l - 1])
        {
            REP(j, d)
            {
                dp[1][(j + dig) % d][l] += dp[0][j][l - 1];
            }
        }
        REP(j, d)
        {
            dp[0][(j + a[l - 1]) % d][l] += dp[0][j][l - 1];
        }
        // REP(j, d)
        // cout << "l:" << l << ",j:" << j << "=" << (dp[1][j][l] + dp[0][j][l]).val() << '\n';
    }
    // 0は常に条件を満たすので除く
    cout << (dp[1][0][n] + dp[0][0][n] - 1).val() << '\n';

    return 0;
}