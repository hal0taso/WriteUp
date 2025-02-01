#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

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
constexpr int MOD = 1000000000 + 7;

template <typename T>
struct CumSum2D
{
  std::vector<std::vector<T>> data;
  CumSum2D(int h, int w) : data(h + 1, std::vector<T>(w + 1, 0)) {}
  void add(int i, int j, T x)
  {
    data[i + 1][j + 1] += x;
  }

  void build()
  {
    for (int i = 0; i < data.size() - 1; ++i)
    {
      for (int j = 0; j < data[i].size() - 1; ++j)
      {
        data[i + 1][j + 1] += data[i + 1][j] + data[i][j + 1] - data[i][j];
      }
    }
  }

  // return sum of [sx, gx) * [sy, gy)
  T query(int sx, int sy, int gx, int gy)
  {
    return data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy];
  }
};

int main()
{
  int n, q;
  cin >> n >> q;
  vector<string> p(n);
  REP(i, n)
  cin >> p[i];

  CumSum2D<ll> sum(n, n);
  REP(i, n)
  REP(j, n)
  if (p[i][j] == 'B')
    sum.add(i, j, 1);
  sum.build();

  REP(i, q)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    ll a1 = (a / n + 1) * n;
    ll b1 = (b / n + 1) * n;
    ll c1 = c - (c % n);
    ll d1 = d - (d % n);

    ll l1, l2;
    l1 = (d1 - b1) / n;
    l2 = (c1 - a1) / n;
    ll ans = sum.query(0, 0, n, n) * l1 * l2;

    a %= n, b %= n, c %= n, d %= n;
    ans += sum.query(a, b, n, n);
    ans += sum.query(0, b, n, n) * l2;
    ans += sum.query(0, b, c + 1, n);
    ans += sum.query(a, 0, n, n) * l1;
    ans += sum.query(0, 0, c + 1, n) * l1;
    ans += sum.query(a, 0, n, d + 1);
    ans += sum.query(0, 0, n, d + 1) * l2;
    ans += sum.query(0, 0, c + 1, d + 1);
    cout << ans << endl;
  }
}
