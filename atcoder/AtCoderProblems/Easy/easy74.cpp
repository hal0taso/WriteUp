#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if (a + b > 2 * c) {
    ans = 2 * c * min(x, y);
  } else {
    ans = (a + b) * min(x, y);
  }
  int z = min(x, y);
  x -= z;
  y -= z;
  if (x > 0) {
    if (2 * c > a) {
      ans += x * a;
    } else {
      ans += x * 2 * c;
    }
  }
  if (y > 0) {
    if (2 * c > b) {
      ans += y * b;
    } else {
      ans += y * 2 * c;
    }
  }
  cout << ans << endl;
  return 0;
}
