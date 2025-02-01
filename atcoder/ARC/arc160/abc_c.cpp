#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

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
constexpr long long INF = 20000000;

// constexpr int MOD = 1000000000 + 7;

int main()
{
  int n;
  cin >> n;

  vector<int> a(n);
  int M = 0, m = INF;
  for (auto &x : a)
  {
    cin >> x;
    M = max(M, x);
    m = min(m, x);
  }
  int K = 0;
  while (n >= (1 << K))
    K++;
  vector<int> b(K + M + 1, 0);
  for (auto x : a)
  {
    b[x]++;
  }
  // dp[i][j]: iがj個ある時のAの選び方
  // dp[i][j] -> dp[i+1][k+b[i+1]] for 0 <= k <= j/2
  vector<mint> dp(n + 1, 0);
  dp[0] = 1;
  int mj = 0;
  for (int i = 1; i <= K + M; i++)
  {
    for (int j = 0; j <= mj; j++)
    {
      mint tmp = dp[j];
      dp[j] = 0;
      dp[j / 2] += tmp;
    }
    for (int j = mj / 2; j > 0; j--)
    {
      dp[j - 1] += dp[j];
    }
    for (int j = mj / 2; j >= 0; j--)
    {
      mint tmp = dp[j];
      dp[j] = 0;
      dp[j + b[i]] += tmp;
    }
    // for (int j = 0; j <= mj; j++)
    // {
    //   cerr << "dp[" << i << "][" << j << "]=" << dp[j].val() << '\n';
    // }
    mj = mj / 2 + b[i];
  }
  // mx = mx / 2 + b[i];

  cout << dp[0].val() << '\n';
  return 0;
}
