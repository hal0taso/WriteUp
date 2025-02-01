#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);

constexpr int MOD = 1000000000 + 7;
long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

long long extGCD(long long a, long long b, long long &x, long long &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main()
{
  ll n, a, b, c, x;
  cin >> n >> a >> b >> c >> x;
  // a >= b >= c
  if (a < b)
    swap(a, b);
  if (a < c)
    swap(a, c);
  if (b < c)
    swap(b, c);
  ll ans = 0;
  cerr << a << ' ' << b << ' ' << c << '\n';
  FOR(i, 1, min(n, x / a) + 1)
  {
    ll y = x - i * a;
    ll j0, k0, d;
    if (c == 1)
    {
      j0 = 0, k0 = 1;
    }
    else
    {
      d = extGCD(b, c, j0, k0);
    }
    cerr << y << '\n';
    // b * j + c * k = y (= d * m')を解く
    if (y % d != 0)
    {
      continue;
    }
    // b * j0 + c * k0 = gcd(b, c)を解く
    cerr << d << ' ' << j0 << ' ' << k0 << '\n';
    // d = gcd(b, c)として
    // b/d * j + c/d * k = 1の整数解の個数を調べる
    // b' = b/d と c' = c/d は互いに素
    b = b / d * y / d;
    c = b / d * y / d;
    // b/d * j0 + c/d0 * k = 1 なので
    // b' * (j - j0) + c' * (k - k0) = 0
    ll lb1, ub1, lb2, ub2;
    // j = c' * m1 + j0
    // k = b' * m2 + k0
    // 1 <= j <= n, 1 <= k <= n となるmの個数を調べる
    // c' * m1 + j0 > 0 -> m1 > -j0 / c'
    lb1 = max(-j0 / c + 1, 1LL);
    lb2 = max(-k0 / b + 1, 1LL);

    // c' * m1 + j0 <= n -> m1 <= n - j0 / c'
    ub1 = min(n, n - (j0 / c + 1LL));
    ub2 = min(n, n - (k0 / b + 1LL));

    ll lb = max(lb1, lb2), ub = min(ub1, ub2);
    cerr << lb1 << ' ' << ub1 << ',' << lb2 << ' ' << ub2 << '\n';
    ans += ub - lb + 1;
  }
  cout << ans << '\n';
  return 0;
}