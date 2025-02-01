#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
// using namespace atcoder;
// using mint = modint1000000007;

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
    int h, w;
    cin >> h >> w;
    vector a(h + 1, vector<ll>(w + 1));
    vector b(h + 1, vector<ll>(w + 1));
    FOR(i, 0, h)
    FOR(j, 0, w)
    cin >> a[i][j];

    FOR(i, 0, h)
    FOR(j, 0, w)
    cin >> b[i][j];

    RFOR(i, 0, h + 1)
    RFOR(j, 1, w + 1)
    a[i][j] -= a[i][j - 1], b[i][j] -= b[i][j - 1];

    RFOR(i, 1, h + 1)
    RFOR(j, 0, w + 1)
    a[i][j] -= a[i - 1][j], b[i][j] -= b[i - 1][j];

    ll ans = 0;
    FOR(i, 0, h - 1)
    FOR(j, 0, w - 1)
    {
        if (a[i][j] != b[i][j])
        {
            int d = b[i][j] - a[i][j];
            a[i][j] += d;
            a[i + 2][j] -= d;
            a[i][j + 2] -= d;
            a[i + 2][j + 2] += d;
            ans += max(d, -d);
        }
    }

    FOR(i, 0, h + 1)
    FOR(j, 0, w + 1)
    if (a[i][j] != b[i][j])
        ans = -1;

    if (ans != -1)
    {
        puts("Yes");
        cout << ans << endl;
    }
    else
    {
        puts("No");
    }
    return 0;
}