#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

constexpr long long INF = 10000;

ll d(int i, int j, vector<vector<ll>> &dp, vector<ll> &fp)
{
    // cout << i << "," << j << '\n';
    if (j - i == 1)
    {
        return dp[i][j] = 0;
    }
    if (dp[i][j] >= 0)
        return dp[i][j];
    ll ans = INF;
    for (int k = j - 1; i < k; k--)
    {
        ans = min(ans, d(i, k, dp, fp) + d(k, j, dp, fp) + fp[j] - fp[i]);
    }
    return dp[i][j] = ans;
}

int main()
{
    long double t, l, x, y, e;
    cin >> t;
    cin >> l >> x >> y;
    long double tx, ty;
    int q;
    cin >> q;
    cout << std::fixed << setprecision(15);
    REP(i, q)
    {
        cin >> e;
        long double degree = e * M_PI * 2.0 / t;
        ty = l / 2.0 - l / 2.0 * cos(degree);
        tx = sqrt(x * x + (y + l / 2.0 * sin(degree)) * (y + l / 2.0 * sin(degree)));
        // cout << "(tx, ty)=(" << tx << "," << ty << ")\n";
        cout << (atan2(ty, tx) * 180.0) / M_PI << endl;
    }
    return 0;
}