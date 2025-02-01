#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int N, K, D;
  cin >> N >> K >> D;
  vector<ll> a(N, 0);
  REP(i, N)
  {
    cin >> a[i];
  }
  vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(K + 1, vector<ll>(D, -1)));
  dp[0][0][0] = 0;
  REP(i, N)
  {
    REP(j, K + 1)
    {
      REP(k, D)
      {
        if (dp[i][j][k] == -1)
          continue;
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
        if (j != K)
          dp[i + 1][j + 1][(k + a[i]) % D] = max(dp[i + 1][j + 1][(k + a[i]) % D], dp[i][j][k] + a[i]);
      }
    }
  }
  cout << dp[N][K][0] << endl;
  return 0;
}
