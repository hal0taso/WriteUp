#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

struct UnionFind
{
  std::vector<long long> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<ll> sz;
  UnionFind(long long N) : par(N), sz(N)
  { // 最初は全てが根であるとして初期化
    for (long long i = 0; i < N; i++)
      par[i] = i, sz[i] = 1;
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
    sz[ry] += sz[rx];
  }

  bool same(long long x, long long y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    long long rx = root(x);
    long long ry = root(y);
    return rx == ry;
  }

  int size(long long x)
  {
    return sz[root(x)];
  }
};

using Graph = vector<vector<int>>;
int main()
{
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  Graph G(n);
  REP(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    uf.unite(u, v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> esize(n, 0);
  vector<ll> vsize(n, 0);
  REP(i, n)
  {
    ll ri = uf.root(i);
    if (vsize[ri] == 0)
    {
      vsize[ri] = uf.size(ri);
    }
    esize[ri] += G[i].size();
  }
  REP(i, n)
  {
    ll ri = uf.root(i);
    if (esize[ri] != 2 * vsize[ri])
    {
      puts("No");
      return 0;
    }
  }
  puts("Yes");

  return 0;
}
