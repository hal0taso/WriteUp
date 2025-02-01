#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 1000000000LL;

void print(vd v)
{
  for (auto vi : v)
  {
    cout << vi << ' ';
  }
  cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
  for (auto vi : v)
  {
    cout << vi.first << ' ';
  }
  cout << '\n';
  for (auto vi : v)
  {
    cout << vi.second << ' ';
  }
  cout << '\n';
}

struct UnionFind
{
  std::vector<long long> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(long long N) : par(N)
  { // 最初は全てが根であるとして初期化
    for (long long i = 0; i < N; i++)
      par[i] = i;
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
  }

  bool same(long long x, long long y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    long long rx = root(x);
    long long ry = root(y);
    return rx == ry;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  UnionFind uf(2 * n);
  REP(i, n)
  {
    uf.unite(2 * i, 2 * i + 1);
  }
  int X = 0;
  REP(i, m)
  {
    int a, b, ai = 0, bi = 0;
    char c, d;
    cin >> a >> c >> b >> d;
    a--, b--;
    if (c == 'B')
      ai++;
    if (d == 'B')
      bi++;
    if (uf.same(2 * a + ai, 2 * b + bi))
    {
      X++;
    }
    uf.unite(2 * a + ai, 2 * b + bi);
  }
  vb seen(2 * n, false);
  int Y = 0;
  REP(i, 2 * n)
  {
    if (!seen[uf.root(i)])
      Y++;
    seen[uf.root(i)] = true;
  }
  cout << X << ' ' << Y - X << '\n';
  return 0;
}
