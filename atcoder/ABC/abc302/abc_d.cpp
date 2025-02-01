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
  int n, m;
  cin >> n >> m;
  ll d;
  cin >> d;
  vector<ll> a(n);
  vector<ll> b(m);
  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;
  sort(all(a));
  sort(all(b));
  ll ans = -1;
  for (auto &x : a)
  {
    auto it = upper_bound(all(b), x + d);

    int pos = distance(b.begin(), it) - 1;
    if (abs(b[pos] - x) <= d)
      ans = max(ans, x + b[pos]);
  }
  for (auto &x : b)
  {
    auto it = upper_bound(all(a), x + d);

    int pos = distance(a.begin(), it) - 1;
    if (abs(a[pos] - x) <= d)
      ans = max(ans, x + a[pos]);
  }
  cout << ans << '\n';
  return 0;
}