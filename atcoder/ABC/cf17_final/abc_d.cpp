#include <bits/stdc++.h>
using namespace std;
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
#define bit(n, k) ((n >> k) & 1)

int main()
{
  int n;
  cin >> n;

  long long h, p;
  vector<tuple<long long, long long, long long>> vec;
  for (int i = 0; i < n; i++)
  {
    cin >> h >> p;
    vec.emplace_back(h + p, h, p);
  }
  std::sort(vec.begin(), vec.end());

  // i番目まで見て, k人以上座布団おいている時の最小の高さ
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
  dp[0][0] = 0;

  FOR(i, 1, n + 1)
  {
    auto &[_, h, p] = vec[i - 1];
    FOR(j, 0, i + 1)
    {
      dp[i][j] = dp[i - 1][j];
      if (j > 0 && dp[i - 1][j - 1] <= h)
      {
        dp[i][j] = min(dp[i - 1][j - 1] + p, dp[i][j]);
      }
    }
  }
  ll ans = 0;
  for (int i = n; i > 0; i--)
    if (dp[n][i] < INF)
    {
      ans = i;
      break;
    }
  cout << ans << '\n';
  return 0;
}
