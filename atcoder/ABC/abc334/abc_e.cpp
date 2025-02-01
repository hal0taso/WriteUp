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

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto &i : s)
    cin >> i;

  UnionFind uf(h * w);
  REP(i, h)
  {
    REP(j, w)
    {
      int v = i * w + j;
      if (i + 1 < h && s[i][j] == '#' && s[i + 1][j] == '#')
        uf.unite(v, v + w);
      if (j + 1 < w && s[i][j] == '#' && s[i][j + 1] == '#')
        uf.unite(v, v + 1);
    }
  }
  set<int> st;
  REP(i, h)
  {
    REP(j, w)
    {
      if (s[i][j] == '#')
        st.insert(uf.root(i * w + j));
    }
  }
  int total = st.size();

  mint ans = 0;
  int red = 0;
  REP(i, h)
  {
    REP(j, w)
    {
      int v = i * w + j;
      if (s[i][j] == '#')
        continue;
      red++;
      set<int> nb;
      if (i + 1 < h && s[i + 1][j] == '#')
        nb.insert(uf.root(v + w));
      if (i - 1 >= 0 && s[i - 1][j] == '#')
        nb.insert(uf.root(v - w));
      if (j + 1 < w && s[i][j + 1] == '#')
        nb.insert(uf.root(v + 1));
      if (j - 1 >= 0 && s[i][j - 1] == '#')
        nb.insert(uf.root(v - 1));
      ans += total + 1 - nb.size();
    }
  }
  ans /= red;
  cout << ans.val() << endl;
}
