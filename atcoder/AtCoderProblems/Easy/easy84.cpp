#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  ll n, l, r, c, ans = 0;
  cin >> n;

  vector<ll> a(n + 1);
  vector<ll> b(n);
  REP(i, n + 1) { cin >> a[i]; }
  REP(i, n) { cin >> b[i]; }
  l = 0;
  r = n - 1;
  while (l < r) {
    c = min(a[l], b[l]);
    ans += c;
    b[l] -= c;
    a[l] -= c;

    c = min(a[l + 1], b[l]);
    ans += c;
    b[l] -= c;
    a[l + 1] -= c;

    c = min(a[r + 1], b[r]);
    ans += c;
    b[r] -= c;
    a[r + 1] -= c;

    c = min(a[r], b[r]);
    ans += c;
    b[r] -= c;
    a[r] -= c;

    l++;
    r--;
  }
  if (r == l) {
    c = min(a[l], b[l]);
    ans += c;
    b[l] -= c;
    a[l] -= c;

    c = min(a[l + 1], b[l]);
    ans += c;
    b[l] -= c;
    a[l + 1] -= c;
  }
  cout << ans << endl;

  return 0;
}
