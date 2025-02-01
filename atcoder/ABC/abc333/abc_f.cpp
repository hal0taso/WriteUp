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
// constexpr int MOD = 1000000000 + 7;

int main()
{
  int N;
  cin >> N;
  mint p = 1;
  p /= 2;
  // dp[i][j]: i人いて, j番目の人が最後まで残る確率
  vector<vector<mint>> dp(N + 1, vector<mint>(N, 0));
  vector<mint> pv(N + 1, 0);
  pv[0] = 1;
  FOR(i, 1, N + 1)
  {
    pv[i] = pv[i - 1] * p;
  }
  dp[1][0] = 1;
  FOR(i, 2, N + 1)
  {
    mint base = 0;
    mint mul = p / (1 - p.pow(i));
    REP(j, i)
    {
      base += dp[i - 1][j] * pv[i - j - 1];
    }
    dp[i][0] += base * mul;
    FOR(j, 1, i)
    {
      dp[i][j] += dp[i][j - 1] * p;
      dp[i][j] += mul * dp[i - 1][j - 1];
      dp[i][j] -= mul * dp[i - 1][j - 1] * pv[i];
    }
  }
  REP(i, N)
  {
    cout << dp[N][i].val();
    if (i == N - 1)
      cout << endl;
    else
      cout << " ";
  }
}
