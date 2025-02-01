#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int MOD = 1e9 + 7;

int main() {
  string n;
  int D;
  cin >> D >> n;
  map<int, ll> dp;
  int eq_sum = 0;
  int nxt_sum;
  for (int i = 0; i < n.size(); i++) {
    int dig = n[i] - '0';
    map<int, ll> nxt_dp;

    // equal -> less (except n[0] == 0)
    REP(d, dig) {
      if (i == 0 && d == 0)
        continue;
      nxt_sum = (eq_sum + d) % D;
      nxt_dp[nxt_sum]++;
      if (nxt_dp[nxt_sum] >= MOD) {
        nxt_dp[nxt_sum] -= (nxt_dp[nxt_sum] / MOD) * MOD;
      }
    }

    // equal -> equal;
    eq_sum = (eq_sum + dig) % D;

    // in the case n[i] > 0 is first non-zero digit
    if (i > 0) {
      FOR(d, 1, 10) {
        nxt_sum = d % D;
        nxt_dp[nxt_sum]++;
        if (nxt_dp[nxt_sum] >= MOD) {
          nxt_dp[nxt_sum] -= (nxt_dp[nxt_sum] / MOD) * MOD;
        }
      }
    }

    // less -> less
    for (const auto &[key, value] : dp) {
      REP(d, 10) {
        nxt_sum = (key + d) % D;
        nxt_dp[nxt_sum] += value;
        if (nxt_dp[nxt_sum] >= MOD) {
          nxt_dp[nxt_sum] -= (nxt_dp[nxt_sum] / MOD) * MOD;
        }
      }
    }
    dp = nxt_dp;
  }
  ll ans = 0;

  // less
  ans += dp[0];

  // equal
  if (eq_sum % D == 0) {
    ans++;
  }
  if (ans >= MOD)
    ans -= (ans / MOD) * MOD;
  cout << ans << endl;
}
