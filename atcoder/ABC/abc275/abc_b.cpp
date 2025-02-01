#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
ll MOD = 998244353;
int main()
{
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a %= MOD;
  b %= MOD;
  c %= MOD;
  d %= MOD;
  e %= MOD;
  f %= MOD;
  ll ans = ((((a * b) % MOD) * c) % MOD) - ((((d * e) % MOD) * f) % MOD);
  if (ans < 0)
  {
    ans += MOD;
  }
  cout << ans << endl;
  // cout << "YES" << endl;
  return 0;
}
