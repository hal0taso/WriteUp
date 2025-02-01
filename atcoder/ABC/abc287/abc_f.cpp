#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
using mint = modint998244353;

using Graph = vector<vector<int>>;

int main()
{
  int n;
  cin >> n;
  int u, v;
  Graph G(n);

  REP(i, n - 1)
  {
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  using vm = vector<mint>;
  using vvm = vector<vm>;

  // dp[v][b][k]: 頂点vを選んだ時(b=1), 選ばなかったとき(b=0)に連結成分数がkである場合の数
  auto dfs = [&](auto f, int v, int p = -1) -> vvm
  {
    // dp[b][k] 頂点 v の部分木であって、vを使うときb=1, 使わないときb=0にそれぞれ連結成分数がkになる部分集合の選び方の数
    vvm dp(2, vm(1, 1));
    for (int u : G[v])
    {
      if (u == p)
        continue;
      vvm r = f(f, u, v);
      int rn = r[0].size(), pn = dp[0].size();
      vvm p(2, vm(rn + pn));
      swap(dp, p);
      REP(i, pn)
      {
        REP(j, rn)
        {
          dp[1][i + j] += p[1][i] * (r[0][j] + r[1][j]);
          dp[0][i + j] += p[0][i] * r[0][j];
          dp[0][i + j + 1] += p[0][i] * r[1][j];
        }
      }
    }
    return dp;
  };

  vvm r = dfs(dfs, 0);
  for (int i = 1; i <= n; i++)
  {
    mint ans = 0;
    if (i < n)
    {
      ans += r[0][i];
    }
    ans += r[1][i - 1];
    cout << ans.val() << '\n';
  }
  return 0;
}