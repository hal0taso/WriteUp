#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

// adjacency list of a directed graph
using Graph = std::vector<std::vector<int>>;

void dfs(Graph G, int s, vector<int> &dist)
{
  // todo リストを表すキュー
  queue<int> que;

  // 頂点 0 を始点とする
  dist[s] = 0;
  que.push(s);

  // キューが空になるまで探索する
  while (!que.empty())
  {
    // キューから頂点を取り出す
    int v = que.front();
    que.pop();

    // 頂点 v から 1 手で行ける頂点 next_v を探索
    for (auto next_v : G[v])
    {
      // 頂点 next_v が探索済みであれば何もしない
      if (dist[next_v] != -1)
      {
        continue;
      }

      // 頂点 next_v を探索する
      dist[next_v] = dist[v] + 1;
      que.push(next_v);
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  Graph G(n);
  Graph Gp(n * n);
  REP(i, n)
  cin >> c[i];
  REP(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  REP(u, n)
  {
    REP(v, n)
    {
      if (c[u] == c[v])
        continue;
      for (int nu : G[u])
      {
        for (int nv : G[v])
        {
          if (c[nu] == c[nv])
            continue;
          Gp[n * u + v].push_back(n * nu + nv);
          Gp[n * nu + nv].push_back(n * u + v);
        }
      }
    }
  }
  int s = n * 0 + n - 1, t = n * (n - 1) + 0;
  vector<int> dist(n * n, -1);
  dfs(Gp, s, dist);
  cout << dist[t] << endl;
}

int main()
{
  int t;
  cin >> t;
  REP(test, t)
  {
    solve();
  }
  return 0;
}
