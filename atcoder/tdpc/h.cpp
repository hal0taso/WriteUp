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
  int N, W, C;
  cin >> N >> W >> C;
  vector<tuple<int, int, int>> itm;
  REP(i, N)
  {
    int w, v, c;
    cin >> w >> v >> c;
    itm.emplace_back(c, w, v);
  }

  /*
  // dp[i][j]: i個目までの荷物を使って重みj以下となる最大の価値
  // Base case
  dp[0][0] = 0;
  // Reccurence relation
  dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i];
  -> 色の情報は？

  // dp[i][j][S]: i個目までの荷物を使って重みj以下かつ色の集合がSとなる最大の価値
  // Base case
  dp[0][0][\emptyset] = 0;
  // Reccurence relation
  // if ((S >> c[i]) & 1) == 0) // Sにc[i]が含まれない
  dp[i][j][S] = dp[i-1][j][S]
  // if ((S >> c[i]) & 1) == 1) // Sにc[i]が含まれる
  dp[i][j][S] = max(dp[i-1][j][S], dp[i-1][j-w[i]][S^c[i]], dp[i-1][j-w[i]]][S]); // i-1個目まで使うとき, i個目を新しい色として使うとき, i個目を既存の色として使うとき
  // -> O(NW2^C)-time
  // 自分の色を追加した時に色の種類数越えなければいいのでは
  */
  sort(all(itm));
  vector dp(C + 1, vector(N + 1, vectorvector<int>(W + 1, 0)));
  vector<int> s;
  int p = -1;
  vector<int> t;
  REP(i, n)
  {
    int q = get<0>(itm[i]);
    if (p != q)
    {
      s.push_back(i);
      if (i > 0)
      {
        t.push_back(i - 1);
      }
    }
    p = q;
  }
  t.push_back(N - 1);
  /*
  dp[k][i][j]: 今k色使っていてi番目までみたときに重さj以内の最大の価値
  dp[0][i][j] = 0
  dp[k][i][j] = dp[k][i-1][j], dp[k-1][i-1][j - w] + v, dp[k][i-1][j-w] + v // if (c[i] == c[i-1])
  */
  FOR(k, 1, C + 1)
  {
    FOR(i, 1, N + 1)
    {
      REP(j, W + 1)
      {
        auto [c, w, v] = itm[i - 1];
        dp[k][j][k] = dp[k][i - 1][j];
      }
    }
  }
  return 0;
}