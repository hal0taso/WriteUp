#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define MOD 998244353
int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    REP(i, N)
    {
        REP(j, K)
        {
            FOR(k, 1, M + 1)
            {
                if (j + k <= K)
                {
                    dp[i + 1][j + k] += dp[i][j];
                    dp[i + 1][j + k] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    FOR(j, 1, K + 1)
    {
        ans += dp[N][j];
        ans %= MOD;
    }
    cout << ans % MOD << endl;
}
