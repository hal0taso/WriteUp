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
constexpr long long INF = (1LL << 60);

constexpr int MOD = 1000000000 + 7;
vector<pair<long long, long long>> prime_factorize(long long N)
{
  vector<pair<long long, long long>> res;
  for (long long a = 2; a * a <= N; ++a)
  {
    if (N % a != 0)
      continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0)
    {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1)
    res.push_back({N, 1});
  return res;
}

int main()
{
  ll n;
  cin >> n;
  const auto &res = prime_factorize(n);
  vector<int> tgt(3);
  for (auto p : res)
  {
    if (p.first != 2 && p.first != 3 && p.first != 5)
    {
      cout << 0 << '\n';
      return 0;
    }
    if (p.first == 2)
      tgt[0] = p.second;
    if (p.first == 3)
      tgt[1] = p.second;
    if (p.first == 5)
      tgt[2] = p.second;
  }
  // dp[i][j][k] (2^i, 3^j, 5^k)になる確率
  vector dp(tgt[0] + 1, vector(tgt[1] + 1, vector<mint>(tgt[2] + 1, 0)));
  mint f = 1;
  f /= 5; // 1/6 * \frac{1- 1/6^N}{1 - 1/6}
  dp[0][0][0] = 1;
  REP(i, tgt[0] + 1)
  {
    REP(j, tgt[1] + 1)
    {
      REP(k, tgt[2] + 1)
      {
        if (i < tgt[0])
          dp[i + 1][j][k] += dp[i][j][k] * f;
        if (j < tgt[1])
          dp[i][j + 1][k] += dp[i][j][k] * f;
        if (i < tgt[0] && j < tgt[1])
          dp[i + 1][j + 1][k] += dp[i][j][k] * f;
        if (i < tgt[0] - 1)
          dp[i + 2][j][k] += dp[i][j][k] * f;
        if (k < tgt[2])
          dp[i][j][k + 1] += dp[i][j][k] * f;
      }
    }
  }
  cout << dp[tgt[0]][tgt[1]][tgt[2]].val() << '\n';
  return 0;
}