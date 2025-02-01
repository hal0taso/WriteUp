#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

struct Edge
{
  int to;
};
using Graph = vector<vector<int>>;
/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
void dfs(const Graph &G, int v, vector<bool> &used, vector<int> &ans)
{
  used[v] = true;
  for (auto next_v : G[v])
  {
    if (!used[next_v])
    {
      dfs(G, next_v, used, ans);
    }
  }
  ans.push_back(v); // 帰りがけにpush_back
}

vector<int> topo_sort(const Graph &G)
{ // bfs
  vector<int> ans;
  int n = (int)G.size();
  vector<bool> used(n, false);
  for (int v = 0; v < n; v++)
  { // 未探索の頂点ごとにDFS
    if (!used[v])
      dfs(G, v, used, ans);
  }
  reverse(ans.begin(), ans.end()); // 逆向きなのでひっくり返す
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  Graph G(n);
  REP(i, m)
  {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    G[x[i]].push_back(y[i]);
  }
  vector<int> ans = topo_sort(G);
  REP(i, n - 1)
  {
    if (find(G[ans[i]].begin(), G[ans[i]].end(), ans[i + 1]) != G[ans[i]].end())
    {
      continue;
    }
    else
    {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  vector<int> ret(n);
  REP(i, n)
  {
    ret[ans[i]] = i + 1;
  }
  REP(i, n)
  {
    cout << ret[i];
    if (i < n - 1)
      cout << ' ';
    else
      cout << '\n';
  }
  return 0;
}
