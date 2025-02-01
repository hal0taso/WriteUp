#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (long long i = a; i < b; ++i)
#define REP(i, n) for (long long i = 0; i < n; ++i)

long long MOD = 1e9 + 7;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
  REP(j, m + 1) { dp[1][j] = 1; }
  FOR(i, 2, n + 1) { dp[i][0] = (dp[i - 1][0] * n) % MOD; }
  FOR(i, 2, n + 1) {
    FOR(j, 1, m + 1) { dp[i][j] = (dp[i - 1] + dp[j - 1]) % MOD; }
  }
  cout << dp[n][m] << endl;
}
