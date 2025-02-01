#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

constexpr long long INF = (1LL << 60);

// adjacency list of a directed graph
using Graph = std::vector<std::vector<int>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// Dijkstra algorithm
// Running time: O((V+E)log(V))
// cf. https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/dijkstra
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph &graph, std::vector<long long> &distances, int startIndex)
{
  // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
  // デフォルトの priority_queue は降順に取り出すため std::greater を使う
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
  q.emplace((distances[startIndex] = 0), startIndex);

  while (!q.empty())
  {
    const long long distance = q.top().first;
    const int from = q.top().second;
    q.pop();

    // 最短距離でなければ処理しない
    if (distances[from] < distance)
    {
      continue;
    }

    // 現在の頂点からの各辺について
    for (const auto &next_v : graph[from])
    {
      // to までの新しい距離
      const long long d = (distances[from] + 1);

      // d が現在の記録より小さければ更新
      if (d < distances[next_v])
      {
        q.emplace((distances[next_v] = d), next_v);
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  Graph G(n);
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  vector<vector<int>> A(n, vector<int>(n, 0));

  REP(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    A[u][v]++;
  }
  int ans = 0;
  REP(i, n)
  {
    Dijkstra(G, dist[i], i);
  }
  REP(i, n)
  {
    REP(j, n)
    {
      if (dist[i][j] < INF && dist[i][j] > 1 && A[i][j] == 0)
      {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
