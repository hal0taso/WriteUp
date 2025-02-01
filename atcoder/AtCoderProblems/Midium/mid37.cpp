#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  int tot = 0;
  int ans = 0;
  REP(i, N) {
    cin >> h[i];
    tot += h[i];
  }
  while (tot > 0) {
    int l = 0, r = 0;
    int m = 100;
    while (r < N) {
      if (h[r] == 0) {
        FOR(i, l, r) { h[i] -= m; }
        tot -= (r - l) * m;
        if (l < r) {
          ans += m;
          // REP(i, N) { cout << h[i] << ","; }
          // cout << endl;
        }
        l = r + 1;
        m = 100;
      } else if (m > h[r]) {
        m = h[r];
      }
      r++;
    }
    FOR(i, l, r) { h[i] -= m; }
    tot -= (r - l) * m;
    if (l < r) {
      ans += m;
      // REP(i, N) { cout << h[i] << ","; }
      // cout << endl;
    }
  }
  cout << ans << endl;
}
