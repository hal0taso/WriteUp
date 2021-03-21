#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

#define MOD 1000000007

int main() {
  vector<ll> a(3);
  ll ans;
  REP(i, 3) { cin >> a[i]; }
  ans = a[0] * a[1] * a[2];
  if (ans % 2 == 1) {
    REP(i, 3) {
      if (a[i % 3] * a[(i + 1) % 3] < ans)
        ans = a[i % 3] * a[(i + 1) % 3];
    }
  } else
    ans = 0;

  cout << ans << endl;
  return 0;
}
