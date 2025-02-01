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
    ll n;
    cin >> n;
    vector<ll> h(n);
    REP(i, n)
    cin >> h[i];

    vector<ll> dp(n, INF);
    dp[0] = 0;
    REP(i, n)
    {
        FOR(j, i + 1, min(n, i + 3))
        {
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}