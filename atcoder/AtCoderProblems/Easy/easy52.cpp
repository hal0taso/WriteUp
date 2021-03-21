#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
int main() {
  int n, bi, ans = 0;
  cin >> n;
  vector<int> b(n + 1);
  FOR(i, 1, n) {
    cin >> bi;
    b[i] = bi;
  }
  b[0] = b[1];
  b[n] = b[n - 1];
  REP(i, n)
  ans += min(b[i], b[i + 1]);
  cout << ans << endl;
  return 0;
}
