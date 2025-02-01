#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;

struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<int> s;

  UnionFind(int N) : par(N), s(N) { //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++) {
      par[i] = i;
      s[i] = 1;
    }
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  int size(int x) { return s[root(x)]; }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x);        // xの根をrx
    int ry = root(y);        // yの根をry
    if (rx == ry)
      return; // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] =
        ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    s[ry] += s[rx];
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

bool cmp(tuple<int, int, ll> e1, tuple<int, int, ll> e2) {
  return get<2>(e1) < get<2>(e2);
}
int main() {
  int N;
  cin >> N;
  ll ans = 0;
  int u, v;
  ll w;
  vector<tuple<int, int, ll>> e(N - 1);
  REP(i, N - 1) {
    cin >> u >> v >> w;
    e[i] = make_tuple(u, v, w);
  }

  sort(e.begin(), e.end(), cmp);

  UnionFind tree(N);
  REP(i, N - 1) {
    u = get<0>(e[i]);
    v = get<1>(e[i]);
    w = get<2>(e[i]);
    ans += w * tree.size(u - 1) * tree.size(v - 1);
    tree.unite(u - 1, v - 1);
  }
  cout << ans << endl;
}
