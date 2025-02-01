#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

constexpr long long MOD = 998244353;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  REP(i, n)
  cin >> a[i] >> b[i];
  // dp[i][j] = i文字目まででj(0:表 1: 裏)を選んだ時の組み合わせ
  vector<vector<long long>> dp(n, vector<ll>(2, 0));
  dp[0][0] = 1;
  dp[0][1] = 1;
  FOR(i, 1, n)
  {
    if (a[i] != a[i - 1])
      dp[i][0] += dp[i - 1][0], dp[i][0] %= MOD;
    if (a[i] != b[i - 1])
      dp[i][0] += dp[i - 1][1], dp[i][0] %= MOD;
    ;
    if (b[i] != a[i - 1])
      dp[i][1] += dp[i - 1][0], dp[i][1] %= MOD;
    ;
    if (b[i] != b[i - 1])
      dp[i][1] += dp[i - 1][1], dp[i][1] %= MOD;
    ;
  }
  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << '\n';

  return 0;
}
