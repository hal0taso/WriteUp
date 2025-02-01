#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main()
{
    int n, x, y;
    ll ans = 0;
    cin >> n >> x >> y;
    vector<int> a(n);
    int l = -1;
    int prev_x = -1;
    int prev_y = -1;
    REP(i, n)
    {
        cin >> a[i];
    }
    REP(r, n)
    {
        if (a[r] == x)
        { // find x
            prev_x = r;
        }
        if (a[r] == y)
        { // find y
            prev_y = r;
        }
        if ((a[r] > x) || (a[r] < y))
        { // extend left
            l = r;
            prev_x = -1;
            prev_y = -1;
        }
        if ((prev_x > -1) && (prev_y > -1))
            ans += min(prev_x, prev_y) - l;
        // cout << "i:" << i << ",l:" << l << ",minl:" << minl << "x:" << prev_x << ",y:" << prev_y << endl;
    }
    std::cout << ans << endl;
}
