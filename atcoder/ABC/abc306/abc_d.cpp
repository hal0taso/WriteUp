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
  int n;
  cin >> n;
  // dp[i][j]: jに対して行動を選択した後に状態iである時の最大の美味しさ
  vector<int> x(n);
  vector<ll> y(n);
  REP(i, n)
  {
    cin >> x[i] >> y[i];
  }
  vector dp(n + 1, vector<ll>(3, -INF));
  dp[0][0] = 0;
  REP(i, n)
  {
    REP(j, 2)
    {
      // cerr << dp[i][j] << ' ';
      if (dp[i][j] == -INF)
        continue;
      dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
      if (x[i] == 1)
      {
        dp[i + 1][j + 1] = max(dp[i][j] + y[i], dp[i + 1][j + 1]);
      }
      else
      {
        dp[i + 1][max(0, j - 1)] = max(dp[i][j] + y[i], dp[i + 1][max(0, j - 1)]);
      }
    }
    // cerr << '\n';
  }
  cout << max(dp[n][0], dp[n][1]) << '\n';
  return 0;
}