#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int powmod(int a, int b) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
  }
  return res;
}

int main() {
  int x;
  cin >> x;
  int a, b;
  int ans = 1, tmp;
  if (x == 1) {
    cout << 1 << endl;
    return 0;
  }
  FOR(a, 1, 101) {
    if (a * a > x)
      continue;
    FOR(b, 2, 10) {
      tmp = pow(a, b);
      if (tmp > x) {
        break;
      }
      if (ans < tmp) {
        ans = tmp;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
