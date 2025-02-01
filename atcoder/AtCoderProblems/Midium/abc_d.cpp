#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (long long i = 0; i < n; ++i)
#define FOR(i, a, b) for (long long i = a; i < b; ++i)
long long INF = -1e15;

int base = 1500;

int ans = 0;
vector<bool> visited(1000, false);
vector<vector<int>> g;
vector<int> dx = {-1, -1, 0, 0, 1, 1};
vector<int> dy = {-1, 0, -1, 1, 0, 1};

void dfs(int v, int p)
{
  visited[v] = true;
  for (auto to : g[v])
  {
    if (!visited[to])
      dfs(to, v);
  }
}

int main()
{
  int n;
  cin >> n;
  g.resize(n);

  vector<vector<int>> idx(3000, vector<int>(3000, -1));
  int x, y;

  REP(i, n)
  {
    cin >> x >> y;
    idx[x + base][y + base] = i;
    for (int j = 0; j < 6; j++)
    {
      int u = idx[x + base + dx[j]][y + base + dy[j]];
      if (u >= 0)
      {
        g[u].push_back(i);
        g[i].push_back(u);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      for (auto to : g[i])
      {
        dfs(to, i);
      }
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
