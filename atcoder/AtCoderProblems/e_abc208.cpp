#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  string n;
  ll k;
  cin >> n >> k;
  ll INF = k + 1;
  map<ll, ull> dp;
  ll eq_prod = 1;
  ll nxt_prod;
  for (int i = 0; i < n.size(); i++) {
    ll dig = n[i] - '0';
    map<ll, ull> nxt_dp;

    // equal -> less (except n[0] == 0)
    REP(d, dig) {
      if (i == 0 && d == 0)
        continue;
      nxt_prod = min(INF, eq_prod * d);
      nxt_dp[nxt_prod]++;
    }

    // equal -> equal;
    eq_prod = min(INF, eq_prod * dig);

    // in the case n[i] > 0 is first non-zero digit
    if (i > 0) {
      FOR(d, 1, 10) {
        nxt_prod = min(INF, d);
        nxt_dp[nxt_prod]++;
      }
    }

    // less -> less
    for (const auto &[key, value] : dp) {
      REP(d, 10) {
        nxt_prod = min(INF, key * d);
        nxt_dp[nxt_prod] += value;
      }
    }
    dp = nxt_dp;
  }
  ull ans = 0;

  // less
  for (const auto &[key, value] : dp) {
    if (key <= k) {
      ans += value;
    }
  }

  // equal
  if (eq_prod <= k) {
    ans++;
  }
  cout << ans << endl;
}
