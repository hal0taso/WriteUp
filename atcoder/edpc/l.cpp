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
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = 1000000000000LL;

constexpr int MOD = 1000000000 + 7;

ll f(int l, int r, vvll &dp, vvll &flag, vll &a)
{
    if (flag[l][r])
        return dp[l][r];
    flag[l][r] = 1;
    if (l == r)
        return dp[l][r] = a[l];
    return dp[l][r] = max(a[l] - f(l + 1, r, dp, flag, a), a[r] - f(l, r - 1, dp, flag, a));
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n)
    cin >> a[i];
    vector dp(n, vector<ll>(n, 0));
    vector flag(n, vector<ll>(n, 0));
    cout << f(0, n - 1, dp, flag, a) << '\n';

    return 0;
}