#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const ll inf = 3e9;
int main()
{
    int n;
    ll x;
    cin >> n;

    vector<ll> a(n + 2, inf);
    FOR(i, 1, n + 1)
    {
        cin >> a[i];
    }
    a[0] = -inf;
    sort(a.begin(), a.end());
    int q;
    int ans = 0;
    cin >> q;
    REP(i, q)
    {
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        size_t pos = distance(a.begin(), it);

        ans = min(x - a[pos - 1], a[pos] - x);
        cout << ans << endl;
    }

    return 0;
}
