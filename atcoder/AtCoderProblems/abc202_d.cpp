#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (long long i = a; i < b; ++i)
#define REP(i, n) for (long long i = 0; i < n; ++i)

int main() {
  long long a, b;
  long long k;
  cin >> a >> b >> k;
  vector<vector<long long>> dp(a + 1, vector<long long>(b + 1, 0));
  dp[0][0] = 1;
  REP(i, a + 1) {
    REP(j, b + 1) {
      if (i > 0) {
        dp[i][j] += dp[i - 1][j];
      }
      if (j > 0) {
        dp[i][j] += dp[i][j - 1];
      }
    }
  }
  while (a > 0 && b > 0) {
    if (k <= dp[a - 1][b]) {
      cout << 'a';
      a -= 1;
    } else {
      k -= dp[a - 1][b];
      cout << 'b';
      b -= 1;
    }
  }
  cout << string(a, 'a');
  cout << string(b, 'b');
  cout << endl;
  return 0;
}
