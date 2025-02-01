#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#include <queue>
// ll MOD = 998244353;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  vector<vector<int>> G(n);

  int u, v;
  vector<long long> c(n);
  REP(i, m)
  {
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
    c[u] += a[v];
    c[v] += a[u];
  }

  priority_queue<pair<long long, int>> que;
  REP(i, n)
  {
    que.push({-c[i], i});
  }
  vector<bool> erased(n, false);
  long long ans = 0;
  while (!que.empty())
  {
    auto [cost, x] = que.top();
    que.pop();
    if (erased[x])
      continue;
    erased[x] = true;
    ans = max(ans, -cost);
    for (auto y : G[x])
    {
      if (!erased[y])
      {
        c[y] -= a[x];
        que.push({-c[y], y});
      }
    }
  }
  cout << ans << endl;

  return 0;
}
