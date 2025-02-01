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
void debug_out()
{
  cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << H << " ";
  debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)
constexpr int MOD = 1000000000 + 7;

// constexpr long long INF = (1LL << 60);

// directed edge
struct Edge
{
  // head of edge
  int to;

  // weight
  long long cost;

  Edge(int v_to, long long v_cost)
  {
    to = v_to;
    cost = v_cost;
  }
};

// adjacency list of a directed graph
using Graph = std::vector<std::vector<Edge>>;

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
    for (const auto &edge : graph[from])
    {
      // to までの新しい距離
      const long long d = (distances[from] + edge.cost);

      // d が現在の記録より小さければ更新
      if (d < distances[edge.to])
      {
        q.emplace((distances[edge.to] = d), edge.to);
      }
    }
  }
}

int main()
{
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  vector d(n, vector<ll>(n, 0));
  REP(i, n)
  REP(j, n)
  cin >> d[i][j];
  Graph G(2 * n);
  // car
  REP(i, n)
  {
    Edge g(i + n, 0);
    G[i].push_back(g);
    FOR(j, i + 1, n)
    {
      Edge e(j, d[i][j] * a);
      G[i].push_back(e);
      Edge f(i, d[i][j] * a);
      G[j].push_back(f);
    }
  }

  // train
  int base = n;
  REP(i, n)
  {
    FOR(j, i + 1, n)
    {
      Edge e(j + n, d[i][j] * b + c);
      G[i + n].push_back(e);
      Edge f(i + n, d[i][j] * b + c);
      G[j + n].push_back(f);
    }
  }

  vector<long long> dist_s(2 * n, INF);
  Dijkstra(G, dist_s, 0);
  cout << dist_s[2 * n - 1] << endl;
  return 0;
}