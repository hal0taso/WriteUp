#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

#define MOD 1000000007

int main() {
  ll n, m, ans = 0, bi, ai;
  cin >> n >> m;
  vector<ll> a;
  map<ll, ll> b;
  REP(i, n) {
    cin >> ai >> bi;
    if (b.find(ai) == b.end()) {
      a.push_back(ai);
      b[ai] = bi;
    } else {
      b[ai] += bi;
    }
  }
  sort(a.begin(), a.end());
  if (b[a[i]] >= m) {
    ans += a[i] * m;
    break;
  } else {
    ans += a[i] * b[a[i]];
    m -= b[a[i]];
  }

  cout << ans << endl;
  return 0;
}
