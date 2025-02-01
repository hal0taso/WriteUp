#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

struct UnionFind
{
  vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(ll N) : par(N)
  { //最初は全てが根であるとして初期化
    for (ll i = 0; i < N; i++)
      par[i] = i;
  }

  ll root(ll x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(ll x, ll y)
  {                  // xとyの木を併合
    ll rx = root(x); // xの根をrx
    ll ry = root(y); // yの根をry
    if (rx == ry)
      return;     // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(ll x, ll y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    ll rx = root(x);
    ll ry = root(y);
    return rx == ry;
  }
};

int main()
{
  ll n;
  int q;
  cin >> n >> q;
  ll op, x, y;
  UnionFind uf = UnionFind(n);

  REP(i, q)
  {
    cin >> op;
    if (op == 1)
      cin >> x >> y;
    else
      cin >> x;
  }
  return 0;
}
