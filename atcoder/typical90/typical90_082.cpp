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

int main()
{
    ll l, r;
    cin >> l >> r;
    // ll ans = 0;
    ll s = 0, t = 0;
    ll tmp = l;
    while (tmp > 0)
    {
        tmp /= 10;
        s++;
    }
    tmp = r;
    while (tmp > 0)
    {
        tmp /= 10;
        t++;
    }
    tmp = 1;
    REP(i, s)
    tmp *= 10;
    // cout << "s:" << s << '\n';
    // cout << "t:" << t << '\n';
    mint x;
    mint ans = 0;
    while (s != t)
    {
        x = (tmp - l);
        x *= (l + tmp - 1);
        x /= 2;
        x = (x * s);
        ans += x;
        l = tmp;
        s++;
        tmp *= 10;
    }
    x = (r - l + 1);
    x *= (l + r);
    x /= 2;
    x = (x * s);
    ans += x;
    // ans += s * (r - l + 1) * (l + r) / 2;
    // ans *= s;
    cout << ans.val() << '\n';
    return 0;
}