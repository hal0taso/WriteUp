#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  ll n;
  ll ans = 0;
  cin >> n;
  vector<ll> a(3 * n);
  REP(i, 3 * n) { cin >> a[i]; }
  sort(a.begin(), a.end());
  a REP(i, n) { ans += a[3 * n - 2 * (i + 1)]; }
  cout << ans << endl;
  return 0;
}
