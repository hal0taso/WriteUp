#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

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
using Graph = vector<vector<int>>;

struct UnionFind
{
  std::vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  std::vector<int> _size;
  UnionFind(int N) : par(N), _size(N)
  { // 最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++)
    {
      par[i] = i;
      _size[i] = 1;
    }
  }

  int root(int x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y)
  {                   // xとyの木を併合
    int rx = root(x); // xの根をrx
    int ry = root(y); // yの根をry
    if (rx == ry)
      return;     // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    _size[ry] += _size[rx];
  }

  bool same(int x, int y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  int size(int x)
  {
    int rx = root(x);
    return _size[rx];
  }
};

/*
グラフ上でトポロジカルソートを行う
*/
vector<int> topological_sort(Graph &G)
{
  vector<int> sorted_vertices;
  queue<int> que;
  vector<int> in_degree(G.size(), 0);

  // 入次数が 0 の頂点をキューに挿入する
  for (int v = 0; v < G.size(); v++)
  {
    for (auto next_v : G[v])
    {
      in_degree[next_v]++;
    }
  }
  for (int v = 0; v < G.size(); v++)
  {
    if (in_degree[v] == 0)
    {
      que.push(v);
    }
  }

  // 幅優先探索
  while (!que.empty())
  {
    // キューから頂点を取り出す
    int v = que.front();
    que.pop();
    sorted_vertices.push_back(v);

    // v へと伸びている頂点たち next_v について、
    // 辺 v --> next_v を削除する
    for (auto next_v : G[v])
    {
      // 辺を削除すると next_v の入次数が 0 になるならば、
      // next_v をキューに挿入する
      in_degree[next_v]--;
      if (in_degree[next_v] == 0)
      {
        que.push(next_v);
      }
    }
  }

  return sorted_vertices;
}

int quadrand(pair<ll, ll> p)
{
  if (p.first >= 0 && p.second >= 0)
  {
    return 0;
  }
  else if (p.first < 0 && p.second >= 0)
  {
    return 1;
  }
  else if (p.first < 0 && p.second < 0)
  {
    return 2;
  }
  else
  {
    return 3;
  }
}

int main()
{
  vector<pair<ll, ll>> p(3);
  REP(i, 3)
  {
    cin >> p[i].first >> p[i].second;
    p[i].first--;
    p[i].second--;
  }
  ll ans = 0;
  ll h1 = abs(p[0].first - p[1].first);
  ll v1 = abs(p[0].second - p[1].second);
  ll h2 = abs(p[2].first - p[1].first);
  ll v2 = abs(p[2].second - p[1].second);
  ans += h1;
  ans += v1;
  ans += h2;
  ans += v2;
  if (h2 > 0 && v2 > 0)
    ans += 2;
  // a, b, c are on same line
  if (p[0].first == p[1].first && p[1].first == p[2].first)
  {
    if (p[0].second - p[1].second > 0 && p[2].second - p[1].second > 0)
      ans += 3;
    else if (p[0].second - p[1].second < 0 && p[2].second - p[1].second < 0)
      ans += 3;
    else
      ans--;
  }
  else if (p[0].second == p[1].second && p[1].second == p[2].second)
  {
    ans = abs(p[0].first - p[1].first) + abs(p[2].first - p[1].first) - 1;
    if (p[0].first - p[1].first > 0 && p[2].first - p[1].first > 0)
      ans += 3;
    else if (p[0].first - p[1].first < 0 && p[2].first - p[1].first < 0)
      ans += 3;
    else
      ans--;
  }
  else
  {
  }
  cout << 0 << endl;
  return 0;
}
