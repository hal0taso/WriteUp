#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
void debug_out()
{
  cout << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cout << H << " ";
  debug_out(T...);
}

#ifdef LOCAL_DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
pair<ll, int> op(pair<ll, int> a, pair<ll, int> b)
{
  if (a.first < b.first)
  {
    return b;
  }
  else
  {
    return a;
  }
}

pair<ll, int> e() { return {-1, -1}; }

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

void print(vector<pair<ll, int>> v)
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

int main()
{
  int n;
  cin >> n;
  map<ll, ll> mr;
  map<ll, ll> mc;
  map<pair<ll, ll>, ll> md;
  REP(i, n)
  {
    ll r, c, x;
    cin >> r >> c >> x;
    // r--, c--;
    mr[r] += x;
    mc[c] += x;
    md[{r, c}] += x;
  }
  ll ans = 0;
  vector<pair<ll, int>> u;
  for (const auto &[key, value] : mr)
    u.push_back({value, key});
  vector<pair<ll, ll>> v;
  for (const auto &[key, value] : mc)
    v.push_back({value, key});
  // print(u);
  sort(all(u));
  reverse(all(u));
  sort(all(v));
  reverse(all(v));

  for (pair<ll, ll> x : v)
  {
    ll tmp = 0;
    for (pair<ll, ll> y : u)
    {
      if (md.count({y.second, x.second}) > 0)
      {
        ll t = x.first + y.first - md[{y.second, x.second}];
        tmp = max(tmp, t);
      }
      else
      {
        ll t = x.first + y.first;
        tmp = max(t, tmp);
        break;
      }
    }
    ans = max(ans, tmp);
  }

  cout << ans << '\n';

  return 0;
}
