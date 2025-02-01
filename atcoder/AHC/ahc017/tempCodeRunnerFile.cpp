#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

constexpr long long INF = (1LL << 60);

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

int main()
{
  int n, m, d, k;
  cin >> n >> m >> d >> k;
  int u, v, w;
  Graph G(n);
  REP(i, m)
  {
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  int x, y;
  REP(i, n)
  {
    cin >> x >> y;
  }
  int cnt = 0;
  REP(i, m)
  {

    cout << i / k + 1;
    if (i < m - 1)
      cout << ' ';
    else
      cout << '\n';
    cnt++;
  }

  return 0;
}
