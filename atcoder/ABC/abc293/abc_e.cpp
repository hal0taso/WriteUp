#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 1000000000LL;

void print(vll v)
{
  for (auto vi : v)
  {
    cout << vi << ' ';
  }
  cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
  for (auto vi : v)
  {
    cout << vi.first << ' ';
  }
  cout << '\n';
  for (auto vi : v)
  {
    cout << vi.second << ' ';
  }
  cout << '\n';
}

ull powmod(ll a, ll b, ll mod)
{
  ull res = 1;
  for (; b; b >>= 1)
  {
    if (b & 1)
    {
      res = res * a % mod;
    }
    a = a * a % mod;
  }
  return res;
}

// xが偶数
// a^0 + ... + a^{x/2-1} + a^{x/2} + ... + a^{x - 1}
// xが奇数
// a^0 + ... + a^{(x-1)/2-1} + a^{(x-1)/2} + ... + a^{(x-1) - 1} + a^{x - 1}

ll solve(ll a, ll x, ll m)
{
  ll ans = 0;
  if (x == 1)
  {
    return 1;
  }
  if (x % 2 == 1)
  {
    ans = powmod(a, x - 1, m);
    x--;
  }
  ll tmp = solve(a, x / 2, m);
  ans += (tmp + tmp * powmod(a, x / 2, m) % m) % m;
  return ans % m;
}
// solve(3, 4, 7)
// 1 + 3 + 9 + 27
// solve(3, 2, 7) = 1 + 3^1 mod 7 = 1 + 3
// solve(3, 1, 7) = 1
int main()
{
  ll a, x, m;
  cin >> a >> x >> m;
  ll ans;
  if (m == 1)
    ans = 0;
  else
    ans = solve(a, x, m);

  cout << ans << '\n';
  return 0;
}
