#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n;
  cin >> n;
  vector<ll> s(n);
  ll m = 1e9 + 1;
  REP(i, n) { cin >> s[i]; }
  vector<ll> t(n);
  int next;
  REP(i, n) {
    cin >> t[i];
    if (t[i] < m) {
      m = t[i];
      next = i;
    }
  }
  vector<ll> ans(n, 0);
  ans[next] = m;
  int prev;
  prev = next;
  next++;
  if (next >= n)
    next = 0;
  while (ans[next] == 0) {
    ans[next] = min(ans[prev] + s[prev], t[next]);
    prev = next;
    next++;
    if (next >= n)
      next = 0;
  }
  REP(i, n) { cout << ans[i] << endl; }

  return 0;
}
