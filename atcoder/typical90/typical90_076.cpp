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
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;

int main()
{
    int n;
    cin >> n;
    ll tot = 0;
    vector<ll> a(n + 1, 0);
    REP(i, n)
    cin >> a[i + 1];
    vector<ll> acc(2 * n + 1, 0);
    FOR(i, 1, n + 1)
    {
        tot += a[i];
        acc[i] = a[i];
        acc[i] += acc[i - 1];
    }
    // cout << tot << endl;
    FOR(i, 1, n + 1)
    {
        acc[n + i] = a[i];
        acc[n + i] += acc[n + i - 1];
    }
    FOR(s, 0, n)
    {
        int l = s;
        int r = s + n;
        int m;
        while (l + 1 < r)
        {
            m = (l + r) / 2;
            if ((acc[m] - acc[s]) * 10 > tot)
                r = m;
            else
                l = m;
        }
        if ((acc[l] - acc[s]) * 10 == tot)
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}