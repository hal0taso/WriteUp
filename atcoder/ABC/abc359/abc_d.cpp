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

  int n;
  cin >> n;
  vector<long long> h(n + 1, 0);
  h[0] = INF;
  vector<long long> rh(n + 1, 0);
  rh[n] = INF;
  vector<long long> g(n + 1, 0);
  debug(0, "h", h[0], "rh", rh[n], "g", g[0]);
  FOR(i, 1, n + 1)
  {
    int x;
    cin >> x;
    h[i] = x
        rh[n - i] = x;
  }
  FOR(i, 1, n + 1)
  {
    auto itr = lower_bound(rh.end() - i - 1, rh.end(), h[i] + 1);
    debug("==rh==");
    for (auto it = rh.end() - i - 1; it != rh.end(); it++)
    {
      debug(*it);
    }
    debug("==rh==");
    debug("*itr=", *itr, "h[i+1]=", h[i]);

    g[i] = distance(rh.end() - i, itr);
    debug(i, "h", h[i], "rh", rh[n - i], "g", g[i]);
  }

  vector<long long> ans(n + 1, 0);
  FOR(i, 1, n + 1)
  {
    ans[i] = ans[i - g[i]] + h[i] * g[i];
  }
  REP(i, n)
  cout << ans[i + 1] + 1 << endl;
}
