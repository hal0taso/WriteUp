#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#include <atcoder/dsu>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

long long modpow(long long a, long long n, long long mod)
{
  long long res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// long long modinv(long long a, long long m)
// {
//   long long b = m, u = 1, v = 0;
//   while (b)
//   {
//     long long t = a / b;
//     a -= t * b;
//     swap(a, b);
//     u -= t * v;
//     swap(u, v);
//   }
//   u %= m;
//   if (u < 0)
//     u += m;
//   return u;
// }
long long MOD = 998244353;
long long INV = 499122177;
int main()
{
  long long n;
  long long m;
  cin >> n >> m;
  vector<int> p(n);
  REP(i, n)
  {
    cin >> p[i];
    p[i]--;
  }
  // cout << modinv(2, MOD) << endl;
  long long ans = 0;
  long long N = n;
  atcoder::dsu uf(n);
  REP(i, n)
  {
    long long pi = p[i];
    if (uf.same(i, pi))
      continue;
    long long tmp = (modpow(m, N - 1, MOD) * (m - 1)) % MOD;
    tmp *= INV;
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
    N--;
    uf.merge(i, pi);
  }
  cout << ans % MOD << endl;

  return 0;
}
