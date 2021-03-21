#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  long long q, h, s, d, n;
  long long ans;
  cin >> q >> h >> s >> d >> n;
  if (2 * q < h)
    h = 2 * q;
  if (2 * h < s)
    s = 2 * h;
  if (2 * s < d)
    d = 2 * s;

  ans = (n / 2) * d + (n % 2) * s;

  cout << ans << endl;

  return 0;
}
