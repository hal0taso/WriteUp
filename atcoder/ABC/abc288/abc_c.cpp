#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

struct UnionFind
{
  std::vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  map<int, int> _size;
  map<int, int> _op_cost;
  int _n;
  UnionFind(int N) : par(N)
  { // 最初は全てが根であるとして初期化
    _n = N;
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

  void unite(int x, int y) // x を y にマージ
  {                        // xとyの木を併合
    int rx = root(x);      // xの根をrx
    int ry = root(y);      // yの根をry
    int sx = size(x);
    int sy = size(y);
    if (rx == ry)
      return;     // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    _size[ry] = sx + sy;
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

int main()
{
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<bool> visited(n, false);
  REP(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    uf.unite(u, v);
  }
  int ans = m;
  REP(i, n)
  {
    int r = uf.root(i);
    if (!visited[r])
    {
      ans -= uf.size(i) - 1;
      visited[r] = true;
    }
  }
  cout << ans << '\n';

  return 0;
}
