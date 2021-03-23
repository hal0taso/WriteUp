#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size() + 1;
  vector<ll> a(n, 0);
  ll ans = 0;
  int up = 0, down = 0;
  FOR(i, 1, n) {
    if (s[i - 1] == '>') {
      if (up > 0) {
        up = 0;
      }
      a[i] = a[i - 1] - 1;
      down++;
    } else {
      if (down > 0) {
        if (a[i - 1] < 0)
          down++;
        FOR(j, i - down, i) { a[j] -= a[i - 1]; }
        down = 0;
      }
      a[i] = a[i - 1] + 1;
      up++;
    }
  }
  if (down > 0) {
    if (a[n - 1] < 0)
      down++;
    FOR(j, n - down, n) { a[j] -= a[n - 1]; }
    down = 0;
  }
  REP(i, n) { ans += a[i]; }
  cout << ans << endl;
  return 0;
}
