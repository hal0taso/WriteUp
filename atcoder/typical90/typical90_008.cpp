#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const ll MOD = 1e9 + 7;
int main()
{
    int n, m;
    string atcoder = "atcoder";
    cin >> n;
    m = atcoder.size();
    string s;
    cin >> s;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    REP(i, n + 1)
    {
        dp[i][0] = 1;
    }
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m + 1)
        {
            dp[i][j] += dp[i - 1][j];
            if (s[i - 1] == atcoder[j - 1])
            {
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
