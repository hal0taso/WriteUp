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

using Graph = vector<vector<int>>;

int main()
{
  int n;
  cin >> n;
  Graph g(n);
  REP(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<ll> c(n);
  REP(i, n)
  {
    cin >> c[i];
  }
  // 頂点0を根とする木DP
  // dp[i]: iの部分木における頂点重みの総和
  vector<ll> dp(n, 0);
  function<void(int, int)> dfs = [&](int v, int p)
  {
    dp[v] = c[v];
    for (int u : g[v])
    {
      if (u == p)
        continue;
      dfs(u, v);
      dp[v] += dp[u];
    }
  };
  dfs(0, -1);
  /*
    debug("dp");
    REP(i, n)
    {
      debug(i, dp[i]);
    }
  */
  // 0からの距離を求める
  vector<ll> dist(n, 0);
  function<void(int, int)> dfs2 = [&](int v, int p)
  {
    for (int u : g[v])
    {
      if (u == p)
        continue;
      dist[u] = dist[v] + 1LL;
      dfs2(u, v);
    }
  };
  dfs2(0, -1);
  /*
    debug("dist");
    REP(i, n)
    {
      debug(i, dist[i]);
    }
  */
  // f(0)の計算
  vector<ll> f(n, 0);
  REP(i, n)
  {
    f[0] += c[i] * dist[i];
  }
  function<void(int, int)> dfs3 = [&](int v, int p)
  {
    for (int u : g[v])
    {
      if (u == p)
        continue;
      f[u] = f[v] - dp[u] + (dp[0] - dp[u]);
      dfs3(u, v);
    }
  };
  /*
    debug("f");
    REP(i, n)
    {
      debug(i, f[i]);
    }
  */
  dfs3(0, -1);
  ll ans = INF;
  // debug(INF);
  REP(i, n)
  {
    ans = min(ans, f[i]);
  }
  cout << ans << endl;
}
