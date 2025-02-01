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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n, 0);
  vector<int> in(n, 0);
  set<pair<int, int>> s;
  set<pair<int, int>> t;
  t.insert({-(1 << 30), n});
  ll ans = 0;

  REP(i, k)
  {
    s.insert({a[i], i});
    in[i] = 1;
  }
  FOR(i, k + 1, n)
  {
    t.insert({a[i], i});
  }
  while (q > 0)
  {
    int x, y;
    cin >> x >> y;
    x--;
    // cerr << "D" << x << ' ' << y << '\n';

    if (in[x] == 0)
    {

      auto [v, idx] = *s.begin();
      // cerr << in[x] << ' ' << v << ' ' << idx << '\n';
      if (v < y)
      {
        s.erase({v, idx});
        t.insert({v, idx});
        in[idx] ^= 1;

        s.insert({y, x});
        t.erase({a[x], x});

        in[x] ^= 1;
        ans -= v;
        ans += y;
      }
      else
      {
        t.erase({a[x], x});
        t.insert({y, x});
      }
    }
    else
    {
      auto [v, idx] = *t.rbegin();
      if (v > y)
      {
        s.erase({a[x], x});
        t.insert({y, x});
        in[x] ^= 1;

        s.insert({v, idx});
        t.erase({v, idx});
        in[idx] ^= 1;
        ans -= a[x];
        ans += v;
      }
      else
      {
        s.erase({a[x], x});
        s.insert({y, x});
        ans -= a[x];
        ans += y;
      }
    }
    a[x] = y;
    cout << ans << '\n';
    q--;
  }

  return 0;
}
