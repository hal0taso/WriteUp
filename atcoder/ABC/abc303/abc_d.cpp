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
  long long x, y, z;
  cin >> x >> y >> z;
  string s;
  cin >> s;
  int n = s.size();
  vector dp(2, vector<long long>(n + 1, INF));
  dp[0][0] = 0;
  dp[1][0] = z;
  FOR(i, 1, n + 1)
  {
    if (s[i - 1] == 'a')
    {
      // 大文字小文字切り替わる
      // dp[cl][i] = min(dp[cl][i-1] + x,
      dp[0][i] = min({dp[0][i - 1] + x, dp[1][i - 1] + z + x, dp[1][i - 1] + y + z});
      dp[1][i] = min({dp[1][i - 1] + y, dp[0][i - 1] + x + z, dp[0][i - 1] + z + y});
    }
    else
    {
      // 大文字小文字切り替わる
      // dp[cl][i] = min(dp[cl][i-1] + x,
      dp[1][i] = min({dp[1][i - 1] + x, dp[0][i - 1] + z + x, dp[0][i - 1] + y + z});
      dp[0][i] = min({dp[0][i - 1] + y, dp[1][i - 1] + x + z, dp[1][i - 1] + z + y});
    }
  }
  cout << min(dp[0][n], dp[1][n]) << '\n';
  return 0;
}