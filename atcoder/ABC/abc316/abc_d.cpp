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
  int n;
  cin >> n;
  vector<int> x(n + 1, 0), y(n + 1, 0), z(n + 1, 0), t(n + 1, 0);
  FOR(i, 1, n + 1)
  cin >> x[i] >> y[i] >> z[i];

  FOR(i, 1, n + 1)
  t[i] = max((x[i] + y[i] + 1) / 2 - x[i], 0);

  int T = 0;
  FOR(i, 1, n + 1)
  T += z[i];
  // dp[i][v] := i番目まで見てvだけ議席を獲得する時の最小コスト
  vector dp(n + 1, vector<ll>(T + 1, INF));
  dp[0][0] = 0;

  FOR(i, 1, n + 1)
  FOR(j, 0, T + 1)
  {
    if (j - z[i] >= 0)
      dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - z[i]] + t[i]);
    else
      dp[i][j] = dp[i - 1][j]; // j-v[i]<0のときはi番目の品物は使えないのだ！
  }
  ll ans = INF;
  for (int tmp = T; tmp * 2 > T; tmp--)
  {
    ans = min(ans, dp[n][tmp]);
  }
  cout << ans << '\n';
  return 0;
}