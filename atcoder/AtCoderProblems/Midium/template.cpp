#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

struct UnionFind
{
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N)
  { //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++)
      par[i] = i;
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
  }

  bool same(int x, int y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main()
{
  int n, m, e;
  cin >> n >> m >> e;
  vector<int> u(e);
  vector<int> v(e);
  for (int i = 0; i < e; i++)
  {
    cin >> u[i] >> v[i];
    if (u[i] > n)
    {
      u[i] = n + 1;
    }
    if (v[i] > n)
    {
      v[i] = n + 1;
    }
  }
  int q;
  cin >> q;
  int xi = 0;
  vector<int> x(e, 0);
  for (int i = 0; i < q; i++)
  {
    cin >> xi;
    x[xi] = 1;
  }
  UnionFind tree(n + 1);

  return 0;
}
