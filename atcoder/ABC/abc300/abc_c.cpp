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

struct UnionFind
{
  std::vector<long long> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  std::vector<long long> _size;
  UnionFind(long long N) : par(N), _size(N)
  { // 最初は全てが根であるとして初期化
    for (long long i = 0; i < N; i++)
    {
      par[i] = i;
      _size[i] = 1;
    }
  }

  long long root(long long x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(long long x, long long y)
  {                         // xとyの木を併合
    long long rx = root(x); // xの根をrx
    long long ry = root(y); // yの根をry
    if (rx == ry)
      return;     // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    _size[ry] += _size[rx];
  }

  bool same(long long x, long long y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    long long rx = root(x);
    long long ry = root(y);
    return rx == ry;
  }

  long long size(int x)
  {
    long long rx = root(x);
    return _size[rx];
  }
};

int v(int i, int j, int h, int w)
{
  return i * w + j;
}

pair<int, int> rv(int v, int h, int w)
{
  return {v / w, v % w};
}
int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  REP(i, h)
  cin >> c[i];
  UnionFind uf(h * w);
  REP(i, h)
  {
    REP(j, w)
    {
      if (c[i][j] == '#')
      {
        if (i > 0 && j > 0)
        {
          if (c[i - 1][j - 1] == '#')
            uf.unite(v(i, j, h, w), v(i - 1, j - 1, h, w));
        }
        if (i > 0 && j < w - 1)
        {
          if (c[i - 1][j + 1] == '#')
            uf.unite(v(i, j, h, w), v(i - 1, j + 1, h, w));
        }
        if (i < h - 1 && j < w - 1)
        {
          if (c[i + 1][j + 1] == '#')
            uf.unite(v(i, j, h, w), v(i + 1, j + 1, h, w));
        }
        if (i < h - 1 && j > 0)
        {
          if (c[i + 1][j - 1] == '#')
            uf.unite(v(i, j, h, w), v(i + 1, j - 1, h, w));
        }
      }
    }
  }
  vector<int> ans(min(h, w));
  vector<bool> seen(h * w);
  REP(i, h)
  {
    REP(j, w)
    {
      int u = v(i, j, h, w);
      int r = uf.root(u);
      if (!seen[r] && uf.size(u) > 1)
      {
        seen[r] = true;
        ans[(uf.size(u) - 1) / 4 - 1]++;
      }
    }
  }
  REP(i, min(h, w))
  {
    cout << ans[i];
    if (i < min(h, w) - 1)
      cout << ' ';
    else
      cout << '\n';
  }
  return 0;
}