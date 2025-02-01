#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
void debug_out()
{
  cout << endl;
}
using mint = modint998244353;
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cout << H << " ";
  debug_out(T...);
}

#ifdef LOCAL_DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 1000000000LL;

void print(vll v)
{
  for (auto vi : v)
  {
    cout << vi << ' ';
  }
  cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
  for (auto vi : v)
  {
    cout << vi.first << ' ';
  }
  cout << '\n';
  for (auto vi : v)
  {
    cout << vi.second << ' ';
  }
  cout << '\n';
}

int main()
{
  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  vector dp(n + 1, vector<mint>(n + 1));
  vector fp(n + 1, vector<mint>(n + 1));
  dp[0][a] = 1;
  fp[0][b] = 1;
  mint prob = 1;
  prob /= p;
  REP(i, n)
  {
    REP(j, n)
    FOR(k, 1, p + 1)
    {
      dp[i + 1][min(j + k, n)] += dp[i][j] * prob;
    }
  }
  FOR(i, 1, n + 1)
  {
    dp[i][n] += dp[i - 1][n];
  }
  prob = 1;
  prob /= q;
  REP(i, n)
  {
    REP(j, n)
    FOR(k, 1, q + 1)
    {
      fp[i + 1][min(j + k, n)] += fp[i][j] * prob;
    }
  }
  mint ans = 0;

  REP(i, n + 1)
  {
    ans += fp[i][n] * dp[i][n];
  }
  cout << ans.val() << '\n';
  return 0;
}
