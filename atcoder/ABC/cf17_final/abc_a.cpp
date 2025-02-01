#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
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
    for (const auto &to : graph[from])
    {
      // to までの新しい距離
      const long long d = (distances[from] + 1);

      // d が現在の記録より小さければ更新
      if (d < distances[to])
      {
        q.emplace((distances[to] = d), to);
      }
    }
  }
}

void print(vd v)
{
  for (auto vi : v)
  {
    cout << vi << ' ';
  }
  cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
  for (auto vi : v)
  {
    cout << vi.first << ' ';
  }
  cout << '\n';
  for (auto vi : v)
  {
    cout << vi.second << ' ';
  }
  cout << '\n';
}

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n, 0));
  Graph G(n);
  REP(i, n)
  REP(j, n)
  {
    cin >> a[i][j];
    if (a[i][j] == 1)
    {
      G[i].push_back(j);
    }
  }
  ll q;
  cin >> q;
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  REP(i, n)
  {
    Dijkstra(G, dist[i], i);
  }
  REP(i, q)
  {
    ll s, t;
    cin >> s >> t;
    s--, t--;
    s %= n;
    t %= n;
    if (s != t)
    {
      if (dist[s][t] < INF)
      {
        cout << dist[s][t] << '\n';
      }
      else
        cout << -1 << '\n';
    }
    else
    {
      ll ans = INF;
      for (int u : G[s])
      {
        ans = min(ans, dist[u][t] + 1);
      }
      if (ans < INF)
      {
        cout << ans << '\n';
      }
      else
      {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}
