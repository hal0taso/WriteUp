#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

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

const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
  const int MOD = mint::mod();
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i;
    inv[i] = MOD - inv[MOD % i] * (MOD / i);
    finv[i] = finv[i - 1] * inv[i];
  }
}

// 二項係数計算
mint COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * finv[k] * finv[n - k];
}

int main()
{
  int n;
  cin >> n;
  mint N = n;
  vector<mint> a(n + 1);
  int ai;
  FOR(i, 1, n + 1)
  {
    cin >> ai;
    a[i] = ai;
  }
  // dp[x] := xにいる時に先貰える期待値
  mint acc = 0;
  vector<mint> dp(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
  {

    acc += dp[i + 1] + a[i + 1];
    dp[i] += acc;
    dp[i] /= N;
  }

  cout << dp[0].val() << endl;
  return 0;
}
