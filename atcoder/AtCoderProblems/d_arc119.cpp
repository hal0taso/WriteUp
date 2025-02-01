#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define MIN(vec) *min_element(vec.begin(), vec.end());

class UnionFind {
public:
  vector<int> par;

  void init(int sz) {
    par.resize(sz, -1);
    for (int i = 0; i < sz; i++)
      par[i] = -1;
  }
  int root(int pos) {
    if (par[pos] == -1)
      return pos;
    par[pos] = root(par[pos]);
    return par[pos];
  }
  void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
      return;
    par[u] = v;
  }
  bool same(int u, int v) {
    if (root(u) == root(v))
      return true;
    return false;
  }
};

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> s(H, vector<int>(W));
  REP(i, H) REP(j, W) cin >> s[i][j];
  UnionFind UF;
  UF.init(H + W);
  set<int> G[H + W];
  REP(i, H + W) G[i].clear();
  REP(i, H) {
    REP(j, W) {
      if (s[i][j] == 'B' || UF.same(i, j + H) == true)
        continue;
      UF.unite(i, j + H);
      G[i].insert(j + H);
      G[j + H].insert(i);
    }
  }
  int remX = H, remY = W;
  vector<tuple<char, int, int>> tup;
  while (true) {
    int idx = -1, idx2 = -1;
    REP(i, H + W) {
      if (G[i].size() != 1)
        continue;
      int to = (*G[i].begin());
      if (G[to].size() != 1) {
        idx = i;
        idx2 = to;
        break;
      }
    }
    if (idx == -1)
      break;
    if (idx < H) {
      tup.push_back(make_tuple('X', idx, idx2 - H));
      remX--;
    } else {
      tup.push_back(make_tuple('X', idx2, idx - H));
      remY--;
    }
    G[idx].erase(idx2);
    G[idx2].erase(idx);
  }

  REP(i, H) {
    if (G[i].size() == 0)
      continue;
    int idx1 = i;
    int idx2 = (*G[i].begin());
    if (remX < remY) {
      tup.push_back(make_tuple('X', idx1, idx2 - H));
      remX--;
    } else {
      tup.push_back(make_tuple('Y', idx1, idx2 - H));
      remY--;
    }
  }

  cout << tup.size() << endl;
  REP(i, tup.size()) {
    cout << get<0>(tup[i]) << " " << get<1>(tup[i]) + 1 << " "
         << get<2>(tup[i]) + 1 << endl;
  }
  return 0;
}
