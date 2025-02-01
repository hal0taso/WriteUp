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

using Graph = vector<vector<int>>;
using color = vector<int>;

/*
グラフGが2彩色可能か判定する <=> 2部グラフ判定を行う.
Gは連結でなくても良い
*/
bool is_bipartite(Graph G)
{
  queue<int> que;
  color c(G.size(), -1);

  for (int s = 0; s < G.size(); s++)
  {
    // sが訪問済みならスキップ
    if (c[s] != -1)
      continue;
    // 頂点 0 を始点とする
    c[s] = 0;
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
        if (c[next_v] != -1)
        {
          // もし訪問済みの頂点が同じ色なら 2 彩色不可能
          if (c[next_v] == c[v])
            return false;

          continue;
        }
        // 頂点 next_v を探索する
        c[next_v] = (c[v] + 1) % 2;
        que.push(next_v);
      }
    }
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  Graph G(n);
  vector<int> a(m), b(m);
  REP(i, m)
  {
    cin >> a[i];
    a[i]--;
  }
  REP(i, m)
  {
    cin >> b[i];
    b[i]--;
  }
  REP(i, m)
  {
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  if (is_bipartite(G))
    puts("Yes");
  else
    puts("No");
}
