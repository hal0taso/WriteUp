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
    int n;
    cin >> n;
    vector<vector<ll>> a(3, vector<ll>(n));
    REP(i, n)
    REP(j, 3)
    cin >>
        a[j][i];
    vector dp(3, vector<ll>(n + 1, 0));
    REP(j, 3)
    dp[j][0] = 0;
    REP(i, n)
    {
        REP(j, 3)
        {
            dp[j][i + 1] = max(dp[(j + 1) % 3][i] + a[(j + 1) % 3][i], dp[(j + 2) % 3][i] + a[(j + 2) % 3][i]);
        }
    }
    ll ans = 0;
    REP(j, 3)
    ans = max(ans, dp[j][n]);
    cout << ans << '\n';
    return 0;
}