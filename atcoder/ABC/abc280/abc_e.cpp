#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const int DENOM = 828542813;

const int MAX = 3e5;
const int MOD = 998244353;

int main()
{
  ll n, p, q;
  cin >> n >> p;
  vector<ll> dp(n + 1);
  q = 100 - p;
  dp[0] = 0;
  dp[1] = 1;
  for (ll i = 2; i <= n; i++)
  {
    dp[i] = 1 + (p * DENOM % MOD) * dp[i - 2] + (q * DENOM % MOD) * dp[i - 1];
    dp[i] %= MOD;
    if (dp[i] < 0)
    {
      dp[i] += MOD;
    }
  }
  cout << dp[n] << endl;
  // cout << "YES" << endl;
  return 0;
}
