#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

constexpr long long INF = (1LL << 60);

ll d(int i, int j, vector<vector<ll>> &dp, vector<ll> &a)
{
    if (j - i == 1)
    {
        // cout << "(" << i << "," << j << ")=" << abs(a[i] - a[j]) << '\n';
        return dp[i][j] = abs(a[i] - a[j]);
    }
    if (dp[i][j] >= 0)
        return dp[i][j];
    ll ans = INF;
    for (int k = j - 2; i < k; k -= 2)
    {
        ans = min(ans, d(i, k, dp, a) + d(k + 1, j, dp, a));
    }
    if (j - i >= 3)
        ans = min(ans, d(i + 1, j - 1, dp, a) + abs(a[j] - a[i]));
    // cout << "(" << i << "," << j << ")=" << ans << '\n';
    return dp[i][j] = ans;
}

int main()
{

    int n;
    cin >> n;
    vector<ll> a(2 * n);
    FOR(i, 0, 2 * n)
    cin >> a[i];
    // dp[i][j] : 区間[i, j]での最小削除コスト
    // dp[i][j] = a[j] - a[i] if j == i+1
    /* dp[i][j] = min(dp[i][j-2] + dp[j-1][j],
                      dp[i][j-4] + dp[j-3][j],...
                      dp[i][i+2] + dp[i+3][j], // 区間の偶奇が入れ替わらないケース
                      dp[i+1][j-1] + abs(a[i] - a[j]), // 区間の偶奇が入れ替わるケース
    */
    vector<vector<ll>> dp(2 * n, vector<ll>(2 * n, -1));
    cout << d(0, 2 * n - 1, dp, a) << '\n';

    return 0;
}