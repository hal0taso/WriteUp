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
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);
#define BIT(n, k) ((n >> k) & 1)

constexpr int MOD = 1000000000 + 7;
using Graph = std::vector<std::vector<int>>;

int main()
{
  ll n, t, m;
  cin >> n >> t >> m;
  Graph G(n, vector<int>(n, 0));
  REP(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u][v] = 1;
    G[v][u] = 1;
  }
  int S = 1 << n;
  set<int> available;
  REP(i, n)
  available.insert(1 << i);
  FOR(s, 1, S)
  {
    bool is_distinct = true;
    REP(i, n)
    {
      if (BIT(s, i) == 0)
        continue;
      FOR(j, i, n)
      {
        if (BIT(s, j) == 0)
          continue;
        if (G[i][j] == 1)
        {
          is_distinct = false;
          break;
        }
      }
      if (!is_distinct)
        break;
    }
    if (is_distinct)
      available.insert(s);
  }
  // T色目まで決めた時にS頂点を塗った時の制約を満たす色塗りの通り数
  vector dp(t + 1, vector<ll>(S, 0));
  dp[0][0] = 1;
  FOR(i, 1, t + 1)
  {
    REP(u, S)
    {
      FOR(v, u + 1, S)
      {
        if ((v & u) == u)
        {
          int w = v ^ u;
          if (available.find(w) != available.end())
            dp[i][v] += dp[i - 1][u];
        }
      }
    }
  }
  int ans = dp[t][S - 1];
  FOR(i, 1, t + 1)
  ans /= i;
  cout << ans << '\n';

  return 0;
}