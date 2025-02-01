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
  vector<ll> p(n);
  vector<pair<ll, ll>> c(m);
  REP(i, n)
  {
    cin >> p[i];
  }
  REP(i, m)
  {
    ll l, d;
    cin >> l >> d;
    c[i] = {l, d};
  }
  sort(all(p));
  sort(all(c));
  ll ans = 0;
  int i = m - 1;
  ll prev = n;
  priority_queue<ll> q;
  while (i > 0)
  {
    auto iter = lower_bound(all(p), c[i]);
    int j = distance(p.begin(), iter);
    if (j < prev)
    {
      int cnt = prev - j;
      while (cnt > 0 && !q.empty())
      {
      }
    }
  }
  return 0;
}