#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c == 1 || d == 1) {
    cout << 0 << endl;
  } else {
    ll LCM = lcm(c, d);
    ll ans;
    ll tot = b / c + b / d - b / LCM;
    ll sub = a / c + a / d - a / LCM;
    ans = (tot - sub);
    if (a % c == 0 || a % d == 0 || a % LCM == 0) {
      ans++;
    }
    cout << (b - a + 1) - ans << endl;
  }
}
