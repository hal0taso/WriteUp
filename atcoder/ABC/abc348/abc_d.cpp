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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h)
  {
    cin >> s[i];
  }
  Graph g(h * w);
  int start = -1, goal = -1;
  REP(i, h)
  {
    REP(j, w)
    {
      if (s[i][j] == 'S')
      {
        start = i * w + j;
      }
      if (s[i][j] == 'T')
      {
        goal = i * w + j;
      }
      if (s[i][j] == '#')
        continue;
      if (i > 0 && s[i - 1][j] != '#')
      {
        g[i * w + j].push_back(Edge((i - 1) * w + j, 1));
        g[(i - 1) * w + j].push_back(Edge(i * w + j, 1));
      }
      if (j > 0 && s[i][j - 1] != '#')
      {
        g[i * w + j].push_back(Edge(i * w + j - 1, 1));
        g[i * w + j - 1].push_back(Edge(i * w + j, 1));
      }
    }
  }
  int n;
  cin >> n;
  vector<int> r(n), c(n), e(n);
  bool is_start = false, is_goal = false;
  int starti, goali;
  REP(i, n)
  {
    cin >> r[i] >> c[i] >> e[i];
    r[i]--;
    c[i]--;
    if (r[i] * w + c[i] == start)
    {
      is_start = true;
      starti = i;
    }
    if (r[i] * w + c[i] == goal)
    {
      is_goal = true;
      goali = i;
    }
  }
  if (!is_start)
  {
    r.push_back(start / w);
    c.push_back(start % w);
    e.push_back(0);
    starti = n;
    n++;
  }
  if (!is_goal)
  {
    r.push_back(goal / w);
    c.push_back(goal % w);
    e.push_back(0);
    goali = n;
    n++;
  }
  vector<vector<long long>> dist(n, vector<long long>(h * w, INF));
  REP(i, n)
  {
    Dijkstra(g, dist[i], r[i] * w + c[i]);
  }
  Graph g2(n);
  REP(i, n)
  {
    REP(j, n)
    {
      if (i == j)
        continue;
      if (dist[i][r[j] * w + c[j]] > e[i])
        continue;
      g2[i].push_back(Edge(j, 1));
    }
  }
  vector<long long> dist2(n, INF);
  Dijkstra(g2, dist2, starti);
  if (dist2[goali] == INF)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}
