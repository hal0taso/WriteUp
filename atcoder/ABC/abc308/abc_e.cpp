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
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  string s;
  cin >> s;
  vector table(3, vector(3, vector<int>(n, 0)));
  REP(i, n)
  {
    if (s[i] == 'M')
    {
      table[0][a[i]][i] = 1;
    }
    if (s[i] == 'E')
    {
      table[1][a[i]][i] = 1;
    }
    if (s[i] == 'X')
    {
      table[2][a[i]][i] = 1;
    }
  }
  // i文字目までみて、"mex" のj番目の文字で, 今Sが含まれている時の組み合わせ
  vector dp(n + 1, vector(3, vector<long long>(1 << 3, 0)));
  // dpテーブルの準備 for M
  FOR(i, 1, n + 1)
  {
    REP(j, 3)
    {
      dp[i][0][1 << j] = table[0][j][i - 1] + dp[i - 1][0][1 << j];
    }
  }
  // for E
  FOR(i, 1, n + 1)
  {
    REP(S, 1 << 3)
    {
      if (s[i - 1] != 'E')
        continue;
      if (((S >> a[i - 1]) & 1) == 1)
        dp[i][1][S] = dp[i - 1][0][S] + dp[i - 1][0][S ^ (1 << a[i - 1])];
    }
  }
  FOR(i, 1, n + 1)
  {
    REP(S, 1 << 3)
    {
      dp[i][1][S] += dp[i - 1][1][S];
    }
  }
  // for X
  FOR(i, 1, n + 1)
  {
    REP(S, 1 << 3)
    {
      if (s[i - 1] != 'X')
        continue;
      if (((S >> a[i - 1]) & 1) == 1)
        dp[i][2][S] = dp[i - 1][1][S] + dp[i - 1][1][S ^ (1 << a[i - 1])];
    }
  }
  FOR(i, 1, n + 1)
  {
    REP(S, 1 << 3)
    {
      dp[i][2][S] += dp[i - 1][2][S];
    }
  }
  long long ans = 0;
  REP(S, 1 << 3)
  {
    set<long long> mex = {0, 1, 2, 3};
    REP(j, 3)
    {
      if (((S >> j) & 1) == 1)
      {
        mex.erase(j);
      }
    }
    long long m = *mex.begin();
    ans += m * dp[n][2][S];
  }
  cout << ans << '\n';
  return 0;
}