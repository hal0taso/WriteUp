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
  int n1, n2;
  int m;
  cin >> n1 >> n2 >> m;
  Graph G(n1 + n2);
  REP(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> dist1(n1 + n2, -1), dist2(n1 + n2, -1);
  bfs(G, 0, dist1);
  bfs(G, n1 + n2 - 1, dist2);
  int ans = 0;
  int ans1 = 0, ans2 = 0;
  REP(i, n1)
  {
    ans1 = max(ans1, dist1[i]);
  }
  FOR(i, n1, n1 + n2)
  {
    ans2 = max(ans2, dist2[i]);
  }
  cout << ans1 + ans2 + 1 << '\n';
  return 0;
}