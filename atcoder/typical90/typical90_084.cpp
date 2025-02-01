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

int m(const char &c)
{
    if (c == 'o')
        return 1;
    else
        return 2;
}

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll l = 0;
    ll r = 0;
    ll f = 0;
    f = m(s[l]);
    while (r < n)
    {
        if (m(s[r]) == f)
        {
        }
        else
        {
            ans += (r - l) * (r - l - 1) / 2 + (r - l);
            l = r;
            f = m(s[l]);
        }
        r++;
    }
    ans += (r - l) * (r - l - 1) / 2 + (r - l);
    ans = n * (n - 1) / 2 + n - ans;
    cout << ans << '\n';
    return 0;
}