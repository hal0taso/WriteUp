#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
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
constexpr int MOD = 1000000000 + 7;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

struct WeightedUnionFind
{
  std::vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  std::vector<int> _size;
  std::vector<ll> weight;

  WeightedUnionFind(int N) : par(N), _size(N), weight(N)
  { // 最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++)
    {
      par[i] = i;
      _size[i] = 1;
      weight[i] = 0LL;
    }
  }

  int root(int x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    int r = root(par[x]);
    weight[x] = weight[par[x]] + weight[x];
    return par[x] = r;
  }

  // unite成功したらtrue, 失敗したらfalseを返す
  // (x, y) が同じ連結成分に属していて、w[y] - w[x] = dのとき,
  // もしくは (x, y) が異なる連結成分に属しているときは, wを更新してtrueを返す.
  // それ以外のときはfalseを返す
  bool unite(int x, int y, ll d)
  {                   // xとyの木を併合
    int rx = root(x); // xの根をrx
    int ry = root(y); // yの根をry
    if (rx == ry)
      return weight[y] - weight[x] == d; // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry;                        // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    _size[ry] += _size[rx];
    weight[rx] = weight[y] - weight[x] - d;
    return true;
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
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, int, ll>> v;
  REP(i, q)
  {
    int a, b;
    ll d;
    cin >> a >> b >> d;
    a--, b--;
    v.emplace_back(i, a, b, d);
  }
  vector<int> ans;
  WeightedUnionFind uf(n);
  for (auto [i, a, b, d] : v)
  {
    if (uf.unite(a, b, d))
      ans.push_back(i + 1);
  }
  int m = ans.size();
  REP(i, m)
  {
    cout << ans[i];
    if (i == m - 1)
      cout
          << endl;
    else
      cout << ' ';
  }
}
