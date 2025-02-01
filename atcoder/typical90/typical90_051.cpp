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

int main()
{
    ll n, k, p;
    ll ans = 0;
    cin >> n >> k >> p;
    vector<vector<ll>> a(2);
    vvll b1(k + 1), b2(k + 1);

    ll ai;
    REP(i, n)
    {
        cin >> ai;
        if (i < n / 2)
            a[1].push_back(ai);
        else
            a[0].push_back(ai);
    }
    REP(i, 1LL << (n - n / 2))
    {
        ll cnt = 0, tmp = 0;
        REP(j, (n - n / 2))
        if ((i >> j) & 1LL)
            cnt++, tmp += a[0][j];
        if (cnt <= k)
            b1[cnt].push_back(tmp);
    }
    REP(i, 1LL << n / 2)
    {
        ll cnt = 0, tmp = 0;
        REP(j, n / 2)
        if ((i >> j) & 1LL)
            cnt++, tmp += a[1][j];
        if (cnt <= k)
            b2[cnt].push_back(tmp);
    }
    REP(i, k)
    sort(all(b1[i])), sort(all(b2[i]));
    // cout << b[0].size() << ' ' << b[1].size() << '\n';
    REP(i, k + 1)
    {
        for (ll bi : b1[i])
        {
            if (bi > p)
                break;
            auto pos = upper_bound(all(b2[k - i]), p - bi);
            ll idx = distance(b2[k - i].begin(), pos);
            ans += idx;
        }
    }
    cout << ans << '\n';

    return 0;
}