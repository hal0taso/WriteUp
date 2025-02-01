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
void debug_out()
{
  cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << H << " ";
  debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)
constexpr int MOD = 1000000000 + 7;

int main()
{
  int n, m, l;
  cin >> n >> m >> l;
  vector<pair<ll, ll>> a(n), b(m);
  ll x;
  REP(i, n)
  {
    cin >> x;
    a[i] = {x, i};
  }
  REP(i, m)
  {
    cin >> x;
    b[i] = {x, i};
  }
  int c, d;
  set<pair<ll, ll>> s;
  REP(i, l)
  {
    cin >> c >> d;
    c--, d--;
    s.insert({c, d});
  }
  sort(all(a));
  sort(all(b));
  reverse(all(b));
  reverse(all(a));
  ll ans = 0;
  REP(i, n)
  {
    ll tmp = 0;
    ll ai = a[i].second;
    REP(j, m)
    {
      ll bi = b[j].second;
      if (s.find({ai, bi}) == s.end())
      {
        tmp = a[i].first + b[j].first;
        break;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
