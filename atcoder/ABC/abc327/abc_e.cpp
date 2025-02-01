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
constexpr long long INF = (1 << 30);
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
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &i : p)
    cin >> i;

  vector<double> denom(n + 1, 1);
  for (int i = 1; i < n; ++i)
  {
    denom[i + 1] = denom[i] * 0.9 + 1.0;
  }
  // dp[i][j]: i番目のコンテストまででj個のコンテストを選んだ時のパフォーマンス(分子)
  vector dp(n + 1, vector<double>(n + 1, 0));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j <= i; ++j)
    {
      // i番目のコンテストを選んだ時
      dp[i + 1][j + 1] = max(0.9 * dp[i][j] + p[i], dp[i + 1][j + 1]);
      // i番目のコンテストを選ばなかった時
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
    }
  }
  double ans = -(double)INF;
  FOR(i, 1, n + 1)
  {
    ans = max(ans, dp[n][i] / denom[i] - 1200. / sqrt(i));
  }
  cout << fixed << setprecision(10) << ans << endl;
}
