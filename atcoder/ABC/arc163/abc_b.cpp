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

int main()
{
  ll n, m;
  cin >> n >> m;
  ll lb, ub;
  vector<ll> a(n - 2);
  cin >> lb >> ub;
  for (ll &x : a)
    cin >> x;
  sort(all(a));
  ll ans = 1LL << 60;
  if (m == 1)
  {
    REP(i, n - 2)
    {
      ll l = a[i], r = a[i];
      ll tmp = max(lb - l, 0LL) + max(r - ub, 0LL);
      ans = min({ans, tmp});
    }
  }
  else
  {
    for (ll i = 0LL; i + m - 1LL < n - 2LL; i++)
    {
      ll l = a[i], r = a[i + (m - 1)];
      ll tmp = max(lb - l, 0LL) + max(r - ub, 0LL);
      ans = min(tmp, ans);
    }
  }
  cout << ans << '\n';
  return 0;
}