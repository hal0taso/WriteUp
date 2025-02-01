#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int gcd(int x, int y) {
  if (x % y == 0) {
    return y;
  } else {
    return gcd(y, x % y);
  }
}
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> x(N);
  REP(i, N) {
    cin >> x[i];
    x[i] -= X;
    if (x[i] < 0)
      x[i] = -x[i];
  }
  int ans = x[0];
  FOR(i, 1, N) { ans = gcd(ans, x[i]); }
  cout << ans << endl;
}
