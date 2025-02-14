#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
// ll MOD = 998244353;

struct UnionFind
{
  vector<int> par, rank, siz;

  // 構造体の初期化
  UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

  // 根を求める
  int root(int x)
  {
    if (par[x] == -1)
      return x; // x が根の場合は x を返す
    else
      return par[x] = root(par[x]); // 経路圧縮
  }

  // x と y が同じグループに属するか (= 根が一致するか)
  bool issame(int x, int y)
  {
    return root(x) == root(y);
  }

  // x を含むグループと y を含むグループを併合する
  bool unite(int x, int y)
  {
    int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
    if (rx == ry)
      return false; // すでに同じグループのときは何もしない
    // union by rank
    if (rank[rx] < rank[ry])
      swap(rx, ry); // ry 側の rank が小さくなるようにする
    par[ry] = rx;   // ry を rx の子とする
    if (rank[rx] == rank[ry])
      rank[rx]++;       // rx 側の rank を調整する
    siz[rx] += siz[ry]; // rx 側の siz を調整する
    return true;
  }

  // x を含む根付き木のサイズを求める
  int size(int x)
  {
    return siz[root(x)];
  }
};

int main()
{
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> C(N);
  for (auto &x : X)
  {
    cin >> x;
    x--;
  }
  for (auto &x : C)
  {
    cin >> x;
  }
  UnionFind uf(N);
  long long ans = 0;
  REP(i, N)
  {
    if (!uf.issame(i, X[i]))
    {
      uf.unite(i, X[i]);
      continue;
    }
    int cur = C[i], v = i;
    do
    {
      v = X[v];
      if (C[v] < cur)
        cur = C[v];

    } while (v != i);
    ans += cur;
  }
  cout << ans << "\n";

  return 0;
}
