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

int main()
{
    int n, s;
    cin >> n >> s;
    vvll a(2, vll(n + 1));
    FOR(i, 1, n + 1)
    cin >> a[0][i] >> a[1][i];
    // dp[i][j][k]: i個目にjを買うときに値がkになるならtrue, ならないならfalse
    vvvb dp(n + 1, vvb(2, vb(s + 1, false)));
    dp[0][0][0] = true;
    dp[0][1][0] = true;
    FOR(i, 1, n + 1)
    {
        REP(k, s + 1)
        {
            REP(b, 2)
            {
                if (k + a[b][i] <= s)
                    dp[i][b][k + a[b][i]] = dp[i - 1][0][k] || dp[i - 1][1][k];
            }
        }
    }
    if (dp[n][0][s] || dp[n][1][s])
    {
        vector<char> ans;
        int tmp = 0;
        for (int i = n; i > 0; i--)
        {
            if (dp[i][0][s - tmp])
                ans.push_back('A'), tmp += a[0][i];
            else if (dp[i][1][s - tmp])
                ans.push_back('B'), tmp += a[1][i];
        }
        reverse(all(ans));
        REP(i, n)
        {
            cout << ans[i];
        }
        cout << '\n';
    }
    else
    {
        puts("Impossible");
    }
    return 0;
}