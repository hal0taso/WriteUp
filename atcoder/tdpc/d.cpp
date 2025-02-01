#include <bits/stdc++.h>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
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
  ll d;
  cin >> n >> d;
  // dp[i][j][k][l]: i手目に2^j, 3^k, 5^lの確率
  // dp[i+1][j][k][l] = dp[i+1][j][k][l] * (1/6) : 1
  // dp[i+1][j+1][k][l] = dp[i+1][j][k][l] * (1/6) : 2
  // dp[i+1][j][k+1][l] = dp[i+1][j][k][l] * (1/6) : 3
  // dp[i+1][j+2][k][l] = dp[i+1][j][k][l] * (1/6) : 4
  // dp[i+1][j][k][l+1] = dp[i+1][j][k][l] * (1/6) : 5
  // dp[i+1][j+1][k+1][l] = dp[i+1][j][k][l] * (1/6) : 6

  vector<int> cnt(3, 0);
  vector<int> p = {2, 3, 5};
  REP(i, 3)
  {
    while (d % p[i] == 0)
    {
      d /= p[i];
      cnt[i]++;
    }
    // cerr << cnt[i] << '\n';
  }
  // cerr << d << '\n';

  vector dp(n + 1, vector(cnt[0] + 1, vector(cnt[1] + 1, vector<double>(cnt[2] + 1))));
  dp[0][0][0][0] = 1.0;
  double f = 1. / 6.;
  FOR(i, 0, n)
  {
    REP(j, cnt[0] + 1)
    {
      REP(k, cnt[1] + 1)
      {
        REP(l, cnt[2] + 1)
        {
          dp[i + 1][j][k][l] += dp[i][j][k][l] * f;
          dp[i + 1][min(j + 1, cnt[0])][k][l] += dp[i][j][k][l] * f;
          dp[i + 1][min(j + 2, cnt[0])][k][l] += dp[i][j][k][l] * f;
          dp[i + 1][j][min(cnt[1], k + 1)][l] += dp[i][j][k][l] * f;
          dp[i + 1][j][k][min(cnt[2], l + 1)] += dp[i][j][k][l] * f;
          dp[i + 1][min(cnt[0], j + 1)][min(cnt[1], k + 1)][l] += dp[i][j][k][l] * f;
        }
      }
    }
  }
  double ans = 0;
  if (d == 1)
  {
    ans = dp[n][cnt[0]][cnt[1]][cnt[2]];
  }

  cout << fixed << setprecision(10);
  cout << ans << '\n';

  return 0;
}
