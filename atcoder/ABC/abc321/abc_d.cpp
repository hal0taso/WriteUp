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
  ll n, m, p;
  cin >> n >> m >> p;
  vector<ll> a(n), b(m);
  REP(i, n)
  cin >> a[i];
  REP(i, m)
  cin >> b[i];
  sort(all(a));
  sort(all(b));
  vector<ll> acc(m + 1, 0);
  FOR(i, 1, m + 1)
  {
    acc[i] = b[i - 1];
    acc[i] += acc[i - 1];
  }
  ll ans = 0;
  REP(i, n)
  {
    ll t = p - a[i];
    auto itr = lower_bound(all(b), t);

    int pos = distance(b.begin(), itr);
    ans += (a[i] * pos) + acc[pos];
    ans += p * (m - pos);
  }
  cout << ans << endl;
  return 0;
}
