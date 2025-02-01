#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

using Graph = std::vector<std::vector<int>>;
vector<bool> seen;

ll dfs(const Graph &G, int v, int n)
{
  // cout << v << endl;
  // seen[v] = true;

  ll ret = 1;

  // bool all_visited = true;
  // for (auto next_v : G[v])
  // {
  //   if (!seen[next_v])
  //     all_visited = false;
  // }
  // if (all_visited)
  //   return 1;

  for (auto next_v : G[v])
  {
    if (seen[next_v])
      continue;
    seen[next_v] = true;
    ret += dfs(G, next_v, n);
    if (ret > 1000000LL)
      break;
    seen[next_v] = false;
  }
  // 帰りがけに要素を追加(探索順に対応するDAGのトポロジカル順序を逆順にしたリストが得られる)
  return ret;
}

int main(void)
{
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; ++i)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  seen.assign(N, false);

  seen[0] = true;
  cout << min(1000000LL, dfs(G, 0, N)) << endl;
  return 0;
}