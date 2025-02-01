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

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  int inf = 10000 + 10;
  vector<pair<int, int>> a(n + 1, {inf, inf});
  FOR(i, 1, n + 1)
  {
    cin >> a[i].first >> a[i].second;
  }
  // dp[i][x][y]: i番目まで見たときに, 甘さの合計がx以下, しょっぱさの合計がy以下となる最大の個数
  // dp[i+1][x][y] = dp[i][x-a[i].first][y-a[i].second] + 1 or dp[i][x][y]
  // dp[i][j][x]: i番目まで見たときに, j個選んだ時の甘さの合計がX以下となる最小のしょっぱさY
  // dp[i+1][j+1][x] = min(dp[i][j][x-a[i].first] + a[i].second, dp[i][j+1][x])
  vector dp(n + 1, vector(n + 1, vector<int>(x + 1, inf)));
  REP(i, n + 1)
  REP(k, x + 1)
  dp[i][0][k] = 0;

  FOR(i, 1, n + 1)
  {
    FOR(j, 1, i + 1)
    {
      REP(k, x + 1)
      {
        if (j < i)
          dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
        if (k - a[i].first >= 0)
          dp[i][j][k] = min(dp[i - 1][j - 1][k - a[i].first] + a[i].second, dp[i][j][k]);
        // debug("! i, j, k, dp", i, j, k, dp[i][j][k]);
      }
    }
  }
  int ans = 0;
  REP(i, n + 1)
  {
    REP(k, x + 1)
    {
      if (dp[n][i][k] <= y)
        ans = i;
    }
  }
  if (ans < n)
    ans++;
  cout << ans << endl;
}
