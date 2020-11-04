#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;

struct UnionFind {
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1) {}
  int find(int x) {
    if (d[x] < 0)
      return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    if (d[x] > d[y])
      swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
};

int main() {

  long n, m;
  cin >> n >> m;
  UnionFind uf(n);
  int a, b;
  REP(i, m) {
    cin >> a >> b;
    --a;
    --b;
    uf.unite(a, b);
  }
  int ans = 0;
  REP(i, n) { ans = max(ans, uf.size(i)); }
  cout << ans << endl;
  return 0;
}
