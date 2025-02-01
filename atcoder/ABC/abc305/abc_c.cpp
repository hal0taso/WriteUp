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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto &x : s)
    cin >> x;
  int a = h, b = -1;
  int c = w, d = -1;
  REP(i, h)
  {
    REP(j, w)
    {
      if (s[i][j] == '#')
      {
        a = min(i, a);
        b = max(i, b);
        c = min(j, c);
        d = max(j, d);
      }
    }
  }
  pair<int, int> ans;
  FOR(i, a, b + 1)
  {
    FOR(j, c, d + 1)
    {
      if (s[i][j] == '.')
      {
        ans = {i, j};
      }
    }
  }
  cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';

  return 0;
}