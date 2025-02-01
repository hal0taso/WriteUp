#include <bits/stdc++.h>
#include <functional>
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

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &x : p)
    cin >> x;
  sort(all(p));
  int N = 10000;
  // dp[i][j] == 今i問目まで見た時にj点である時に到達可能なら1, o.w. 0
  vector dp(n + 1, vector<int>(N + 1, 0));
  // vector<int> dp(N + 1, 0);
  dp[0][0] = 1;
  // dp[0] = 1;
  FOR(i, 1, n + 1)
  REP(j, N + 1)
  {
    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    if (j + p[i - 1] <= N)
      dp[i][j + p[i - 1]] = max(dp[i][j + p[i - 1]], dp[i - 1][j]);
    // dp[j + p[i]] += dp[j];
  }
  int ans = 0;
  REP(i, N + 1)
  if (dp[n][i] > 0)
    ans++;
  cout << ans << '\n';

  return 0;
}
