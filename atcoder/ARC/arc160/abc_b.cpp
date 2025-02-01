#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

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

// constexpr int MOD = 1000000000 + 7;

void solve()
{
  ll n;
  cin >> n;
  ll m = 0;
  mint ans = 0;
  do
  {
    m++;
  } while (m * m < n);
  if (m * m > n)
    m--;
  ans += m * m * m;
  cerr << n << "|" << ans.val() << '\n';
  vector<ll> v;
  vector<ll> u;
  v.push_back(0);
  u.push_back(m);
  for (ll i = n / (m + 1); i > 0; i--)
  {
    v.push_back(i);
    u.push_back(n / i);
  }
  // reverse(all(u));
  // reverse(all(v));
  for (int i = 1; i < u.size(); i++)
  {
    ans += 3 * v[i] * v[i] * (u[i] - u[i - 1]);
  }
  cerr << n << "|" << ans.val() << '\n';
  cout << ans.val() << '\n';
}
int main()
{
  int t;
  cin >> t;
  while (t > 0)
  {
    solve();
    t--;
  }
  return 0;
}
