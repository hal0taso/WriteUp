#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <cstdint>
#include <limits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

const ll MOD = 1000000007LL;
int main()
{
    ll k;
    cin >> k;
    ll tmp = 0;
    ll _k = k;
    while (_k > 0)
    {
        tmp += _k % 10;
        _k /= 10;
    }
    ll ans = 0;
    if (tmp % 9 != 0)
    {
        ans = 0;
    }
    else
    {
        // dp[i] : 各桁の和がi
        // dp[i] += dp[i - x] + 1 for x = 1, ..., 9;
        vector<ll> dp(k + 1, 0);
        dp[0] = 1;

        FOR(i, 1, k + 1)
        {
            for (ll x = 1; x <= min(i, 9LL); x++)
            {
                dp[i] += dp[i - x];
                dp[i] %= MOD;
            }
        }

        ans = dp[k] % MOD;
        // ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}