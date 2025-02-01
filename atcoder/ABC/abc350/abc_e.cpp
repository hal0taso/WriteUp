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


pair<ll, double> memo;

ll f(ll n, ll a, ll x, ll y)
{
  if (n == 0)
    return 0;
  if (memo.find(n) != memo.end())
    return memo[n];
  ll res = INF;
  if (n % a == 0)
    res = min(res, f(n / a, a, x, y) + x);
  else
  {
    res = min(res, f(n - 1, a, x, y) + y);
    res = min(res, f(n + 1, a, x, y) + y);
  }
  return res;
}
int main()
{
  ll n, a, x, y;
  cin >> n >> a >> x >> y;
  // dp[N]: Nが与えられた時に0にするまでに払った金額の期待値の最小値  
  map<ll, double> dp;
  dp[n] = 0;

  for (auto i = dp.rbegin(); i != dp.rend(); i++)
  {
    FOR(i, 2, 7){
      if (dp.find(n/i) == dp.end())
        dp[n/i] = INF;
      if (x < y && i == a)
        dp[n/i] = min(dp[n/i], dp[n] + x);
      else
        dp[n/i] = min(dp[n/i], dp[n] + y6.0/5.0);
    }
  }
  cout << dp[0] << endl;

}
