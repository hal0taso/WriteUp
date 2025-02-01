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

constexpr int MOD = 1000000000 + 7;
// adjacency list of a directed graph
using Graph = std::vector<std::vector<int>>;

void bfs(Graph G, int s, vector<int> &dist)
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
int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  Graph G(n);
  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> height(n, -1);
  priority_queue<pair<int, int>> que;
  vector<int> p(k), h(k);
  REP(i, k)
  {
    cin >> p[i] >> h[i];
    p[i]--;
    height[p[i]] = h[i];
    que.push({h[i], p[i]});
  }
  while (!que.empty())
  {
    auto [hi, u] = que.top();
    hi--;
    que.pop();
    for (int next_u : G[u])
    {
      if (height[next_u] < hi)
      {
        height[next_u] = hi;
        que.push({hi, next_u});
      }
    }
  }
  int ans = 0;
  vector<int> ansvec;
  REP(i, n)
  {
    if (height[i] >= 0)
    {
      ans++;
      ansvec.push_back(i + 1);
    }
  }
  cout << ans << '\n';
  REP(i, ans)
  {
    cout << ansvec[i];
    if (i < ans - 1)
      cout << ' ';
    else
      cout << '\n';
  }

  return 0;
}