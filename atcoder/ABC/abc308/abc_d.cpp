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

bool snuke(char a, char b)
{
  string s = "snuke";
  REP(i, 5)
  {
    if (a == s[i] && b == s[(i + 1) % 5])
      return true;
  }
  return false;
}
int main()
{
  int h, w;

  cin >> h >> w;

  vector<string> S(h);
  for (auto &x : S)
    cin >> x;

  Graph G(h * w);
  vector<int> dist(h * w, -1);
  REP(i, h)
  {
    REP(j, w)
    {
      int v = i * w + j;
      for (int dx : {-1, 1})
      {
        if (i + dx < h && i + dx >= 0)
        {
          int u = (i + dx) * w + j;
          if (snuke(S[i][j], S[i + dx][j]))
            G[v].push_back(u);
        }
      }
      for (int dy : {-1, 1})
      {
        if (j + dy < w && j + dy >= 0)
        {
          int u = i * w + j + dy;
          if (snuke(S[i][j], S[i][j + dy]))
            G[v].push_back(u);
        }
      }
    }
  }
  bfs(G, 0, dist);
  if (dist[h * w - 1] >= 0)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}