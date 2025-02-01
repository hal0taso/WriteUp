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

constexpr int MOD = 1000000000 + 7;

int main()
{
  int W, H;
  cin >> W >> H;
  int N;
  cin >> N;
  vector<pair<int, int>> p;
  REP(i, N)
  {
    int x, y;
    cin >> x >> y;
    p.emplace_back(x, y);
  }
  int A, B;
  cin >> A;
  vector<int> a(A);
  for (auto &x : a)
    cin >> x;
  a.push_back(W);
  cin >> B;
  vector<int> b(B);
  for (auto &x : b)
    cin >> x;
  b.push_back(H);
  map<pair<int, int>, int> m;
  REP(i, N)
  {
    int x, y;
    auto it = lower_bound(all(a), p[i].first);
    if (it != a.end())
    {
      x = distance(a.begin(), it);
    }
    it = lower_bound(all(b), p[i].second);
    if (it != b.end())
    {
      y = distance(b.begin(), it);
    }
    m[{x, y}]++;
  }
  int maxv = 0, minv = N;
  int cnt = 0;
  for (const auto &item : m)
  {
    maxv = max(maxv, item.second);
    minv = min(minv, item.second);
    cnt++;
  }
  if (cnt != (A + 1) * (B + 1))
    minv = 0;
  cout << minv << ' ' << maxv << '\n';
  return 0;
}