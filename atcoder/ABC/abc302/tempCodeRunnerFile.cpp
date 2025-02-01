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
#define dbgl cerr << "DEBUG\n";
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);
#define bit(n, k) ((n >> k) & 1)
constexpr int MOD = 1000000000 + 7;

using Graph = vvi;

void Dijkstra(const Graph &graph, std::vector<long long> &distances, int startIndex)
{
  // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
  // デフォルトの priority_queue は降順に取り出すため std::greater を使う
  std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> q;
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
    for (const auto to : graph[from])
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

int main()
{
  int h, w, T;
  cin >> h >> w >> T;
  vector<string> a(h);
  REP(i, h)
  cin >> a[i];

  int n = 0;
  Graph G(h * w);
  int s, t;
  auto p = [](int x, int y, int w)
  { return x * w + y; };

  vector<int> terminal;
  REP(i, h)
  {
    REP(j, w)
    {
      int u = p(i, j, w);
      if (a[i][j] == 'S')
        s = u, n++;
      if (a[i][j] == 'G')
        t = u, n++;
      if (a[i][j] == 'o')
        terminal.push_back(u), n++;
      if (a[i][j] == '#')
        continue;
      for (int dx : {-1, 1})
      {
        if (i + dx < h && i + dx >= 0 && a[i + dx][j] != '#')
        {
          int v = p(i + dx, j, w);
          G[u].push_back(v);
          G[v].push_back(u);
        }
      }
      for (int dy : {-1, 1})
      {
        if (j + dy < w && j + dy >= 0 && a[i][j + dy] != '#')
        {
          int v = p(i, j + dy, w);
          G[u].push_back(v);
          G[v].push_back(u);
        }
      }
    }
  }
  terminal.push_back(t);
  reverse(all(terminal));
  terminal.push_back(s);
  reverse(all(terminal));
  // dbgl;
  vector<vector<ll>> dist(n, vector<ll>(h * w, INF));
  REP(i, n)
  {
    int u = terminal[i];
    Dijkstra(G, dist[i], u);
  }
  // REP(i, n)
  // {
  //   cerr << "terminal: (" << terminal[i] / w << "," << terminal[i] % w << ")"
  //        << ":\n";
  //   REP(j, n)
  //   {
  //     cerr << "terminal: (" << terminal[j] / w << "," << terminal[j] % w << ")=" << dist[i][terminal[j]] << ' ';
  //   }
  //   cerr << '\n';
  // }
  // dbgl;
  // dp[S][v]:Sを通ってvまで来た時の最短路
  vector dp(1 << n, vector<ll>(n, INF));
  dp[1][0] = 0;
  FOR(S, 2, 1 << n)
  {
    REP(i, n)
    {
      if (bit(S, i))
      {
        REP(j, n)
        {
          if (i == j)
            continue;
          if (bit(S ^ (1 << i), j))
          {
            // dbgl;
            // cerr << S << ":" << i << "(" << terminal[i] / w << "," << terminal[i] % w << "):"
            //      << j << "(" << terminal[j] / w << "," << terminal[j] % w << "):" << dp[S ^ (1 << i)][j] << '\n';
            dp[S][i] = min(dp[S][i], dp[S ^ (1 << i)][j] + dist[i][terminal[j]]);
          }
        }
      }
    }
  }
  int ans = -1;
  FOR(S, 1, 1 << n)
  {
    // cerr << S << ":" << dp[S][n - 1] << '\n';
    if (bit(S, 0) && dp[S][n - 1] <= T)
    {
      int k = __builtin_popcount(S) - 2;
      ans = max(ans, k);
    }
  }
  cout << ans << '\n';

  return 0;
}