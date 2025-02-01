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

int count(int n, vector<ll> &a, ll b, ll x)
{
  // count the number of elements in a whose distance from b is less than or equal x
  int ansL, ansR;
  int l = -1, r = n;
  while (r - l > 1)
  {
    int m = (l + r) / 2;
    if (a[m] - b <= x)
    {
      l = m;
    }
    else
    {
      r = m;
    }
  }
  ansR = l;
  l = -1, r = n;
  while (r - l > 1)
  {
    int m = (l + r) / 2;
    if (b - a[m] <= x)
    {
      r = m;
    }
    else
    {
      l = m;
    }
  }
  ansL = r;
  int ans = ansR - ansL + 1;
  // debug("!", x, ans);
  return ans;
}

ll solve(int n, vector<ll> &a, ll b, int k)
{
  // find the k-th smallest distance of all distances of element of a and b
  ll l = -1, r = 200000010;
  while (r - l > 1)
  {
    ll m = (l + r) / 2;
    if (count(n, a, b, m) >= k)
    {
      r = m;
    }
    else
    {
      l = m;
    }
  }
  return r;
}

int main()
{
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> b(q);
  vector<ll> k(q);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, q)
  {
    cin >> b[i] >> k[i];
  }
  sort(all(a));
  REP(i, q)
  {
    ll ans = solve(n, a, b[i], k[i]);
    cout << ans << endl;
  }
}
