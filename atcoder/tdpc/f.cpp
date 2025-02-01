#include <bits/stdc++.h>
#include <atcoder/modint>
#include <functional>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;
constexpr long long INF = (1LL << 60);

int main()
{
  int N, K;
  cin >> N >> K;
  // 駅iにいる時にj駅連続で停車している時の組み合わせ
  // for j = 1,...k-1
  // dp[i][j] = dp[i-1][j-1]; // 直前にi-1で停車して、iで停車する
  //
  // dp[i][0] = sum_{k=1}^{i-2} \sum{l = 0}^{K-1} dp[k][l] // i-1で停車せずにiで停車するとき
  // vector dp(N + 1, vector<mint>(K, 0));

  // vector<mint> mem(K, 0);
  // // mem[0] = 1;
  // // mint curr = 1;
  // mem[0] = 1;
  mint ans = 0;
  // FOR(i, 1, N + 1)
  // {
  //   mem[i % K] = mem[(i - 1 + K) % (K)] - mem[i % (K)] + mem[(i - 2 + K) % (K)];
  //   // -= mem[i % (K - 1)];
  //   // curr += mem[(i - 2 + K) % (K - 1)];
  //   // mem[i % K] = curr;
  //   cerr << mem[i % (K)].val() << '\n';
  // }
  // ans = mem[N % (K)];
  // K--;
  // vector dp(N + 1, vector<mint>(K + 1, 0));
  // dp[1][1] = 1;
  // mint tmp, tot = 0;
  // FOR(i, 2, N + 1)
  // {
  //   mint tmp = 0;
  //   // FOR(j, 1, K + 1)
  //   // {
  //   //   tmp += dp[i - 1][j];
  //   // }

  //   dp[i][1] += tot;
  //   FOR(j, 2, K + 1)
  //   {
  //     dp[i][j] = dp[i - 1][j - 1];
  //     // tmp += dp[i - 1][j];
  //   }
  //   tot += tmp;
  // }
  K--;
  vector<mint> dp(N + 1, 0);
  dp[1] = 1;
  mint tmp, tot = 0, row = 0;
  FOR(i, 2, N + 1)
  {
    row += dp[i - 1];
    row -= dp[max(i - K - 1, 0)];

    dp[i] += tot;
    tot += row;
  }
  ans = 0;
  // FOR(i, 1, N + 1)
  // {
  //   cout << i << "|";
  //   FOR(j, 1, K + 1)
  //   {
  //     cout << dp[i][j].val() << ' ';
  //   }
  //   cout << endl;
  // }
  // REP(j, K + 1)
  // {
  //   ans += dp[N][j];
  // }
  REP(j, K)
  ans += dp[N - j];
  cout << ans.val() << '\n';
  return 0;
}
