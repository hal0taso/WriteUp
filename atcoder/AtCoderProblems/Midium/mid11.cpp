#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, m, ans;
  ll x, y, d, dist;
  cin >> n >> m;
  vector<pair<ll, ll>> s(n);
  vector<pair<ll, ll>> c(m);
  REP(i, n) {
    cin >> x >> y;
    s[i] = make_pair(x, y);
  }
  REP(i, m) {
    cin >> x >> y;
    c[i] = make_pair(x, y);
  }
  REP(i, n) {
    d = 10000000000;
    REP(j, m) {
      dist = abs(s[i].first - c[j].first) + abs(s[i].second - c[j].second);
      if (dist < d) {
        d = dist;
        ans = j;
      }
    }
    cout << ans + 1 << endl;
  }

  return 0;
}
