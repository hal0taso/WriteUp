#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

// adjacency list of a directed graph
using Graph = std::vector<std::vector<int>>;
vector<int> order, component;
vector<bool> seen;
vector<int> comp_size;

void dfs(const Graph &G, int v)
{
  seen[v] = true;
  for (auto next_v : G[v])
  {
    if (!seen[next_v])
      dfs(G, next_v);
  }
  // 帰りがけに要素を追加(探索順に対応するDAGのトポロジカル順序を逆順にしたリストが得られる)
  order.push_back(v);
}

void rdfs(const Graph &rG, int v, int k)
{
  component[v] = k;
  for (auto next_v : rG[v])
  {
    if (component[next_v] < 0)
    {
      rdfs(rG, next_v, k);
    }
  }
}

int scc(const Graph &g)
{
  int n = g.size();
  Graph rg(n);
  component.assign(n, -1);
  seen.assign(n, false);
  int last_ptr = 0;
  REP(v, n)
  {
    for (auto nv : g[v])
      rg[nv].push_back(v);
  }
  REP(v, n)
  {
    if (!seen[v])
      dfs(g, v);
  }
  int k = 0;
  reverse(order.begin(), order.end());
  for (auto v : order)
    if (component[v] < 0)
      rdfs(rg, v, k), k++;
  comp_size.assign(k, 0);
  REP(v, n)
  comp_size[component[v]]++;

  return k;
}

int main()
{
  int n, m;
  cin >> n >> m;
  Graph g(n);
  int a, b;
  REP(i, m)
  {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int k;
  k = scc(g);
  if (k != 1)
  {
    puts("No");
    return 0;
  }
  int leaf = 0;
  REP(i, n)
  {
    if (g[i].size() == 1)
    {
      leaf++;
    }
    else if (g[i].size() == 2)
    {
      continue;
    }
    else
    {
      puts("No1");
      return 0;
    }
  }
  if (leaf == 2)
  {
    puts("Yes");
  }
  else
  {
    puts("No2");
  }

  return 0;
}
