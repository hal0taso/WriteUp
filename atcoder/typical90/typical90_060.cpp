#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 400000;

void print(vll v)
{
    for (auto vi : v)
    {
        cout << vi << ' ';
    }
    cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
    for (auto vi : v)
    {
        cout << vi.first << ' ';
    }
    cout << '\n';
    for (auto vi : v)
    {
        cout << vi.second << ' ';
    }
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;
    vll a(n);
    REP(i, n)
    cin >> a[i];
    vll dp(n, INF), fp(n, INF);
    vector<pair<ll, ll>> l(n, {INF, INF}), m(n, {INF, INF});
    ll idx;
    ll lis;
    REP(i, n)
    {
        idx = lower_bound(all(dp), a[i]) - dp.begin();
        dp[idx] = a[i];
        lis = lower_bound(all(dp), INF) - dp.begin();
        l[i] = {lis, dp[idx]};
        idx = lower_bound(all(fp), a[n - i - 1]) - fp.begin();
        fp[idx] = a[n - i - 1];
        lis = lower_bound(all(fp), INF) - fp.begin();
        m[i] = {lis, fp[idx]};
        // puts("---");
        // print(dp);
        // print(lis);
        // print(fp);
        // print(mis);
    }
    reverse(all(fp));
    reverse(all(m));
    ll ans = 1;
    REP(i, n - 1)
    {
        auto [x, xv] = l[i];
        auto [y, yv] = m[i + 1];
        if (xv != yv)
            ans = max(x + y, ans);
    }
    cout << ans << '\n';
    return 0;
}