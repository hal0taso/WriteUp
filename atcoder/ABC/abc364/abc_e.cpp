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

// adjacency list of a directed graph
using Graph = std::vector<std::vector<int>>;

pair<int, int> get_ij(int n, int w)
{
  return make_pair(n / w, n % w);
}

int main()
{
  int h, w, y;
  cin >> h >> w >> y;
  int n = h * w;
  vector a(h, vector<int>(w, 0));
  REP(i, h)
  {
    REP(j, w)
    {
      cin >> a[i][j];
    }
  }
  Graph G(n); // 辺がある -> 隣あっている
  vector used(h, vector<bool>(w, false));
  priority_queue<pair<int, int>> pq;
  REP(i, h)
  {
    REP(j, w)
    {
      if (i + 1 < h)
      {
        G[i * w + j].push_back((i + 1) * w + j);
        G[(i + 1) * w + j].push_back(i * w + j);
      }
      if (j + 1 < w)
      {
        G[i * w + j].push_back(i * w + j + 1);
        G[i * w + j + 1].push_back(i * w + j);
      }
      if (i == h - 1 || j == w - 1 || i == 0 || j == 0)
      {
        // G[i*w+j].push_back(n);
        // G[n].push_back(i*w+j);
        used[i][j] = true;
        pq.push(make_pair(-a[i][j], i * w + j));
      }
    }
  }
  int now = 0;
  int sink = 0;
  vector<int> ans(y + 1, 0);
  while (now < y && !pq.empty())
  {
    now++;
    auto [c, v] = pq.top();
    c = -c;
    if (now < c)
    {
      // debug("C", now, sink, c);
      ans[now] = n - sink;
      continue;
    }
    // now以下の頂点に隣接する頂点をbfs -> now未満なら沈めて次を探索
    // whileの外で選んだvは強制的に沈める
    while (!pq.empty() && now >= -pq.top().first)
    {
      c = pq.top().first;
      v = pq.top().second;
      c = -c;
      pq.pop();
      sink++;
      for (auto nv : G[v])
      {
        auto [x, y] = get_ij(nv, w);
        if (!used[x][y])
        {
          pq.push(make_pair(-a[x][y], nv));
          used[x][y] = true;
        }
      }
    }
    ans[now] = n - sink;
  }

  FOR(i, 1, y + 1)
  {
    cout << ans[i] << endl;
  }
  return 0;
}
