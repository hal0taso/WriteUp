#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
const long long INF = 1e18;
int main(void)
{

  int N;
  cin >> N;
  vector<long long> A(N);
  vector<string> S(N);
  REP(i, N)
  cin >> A[i];
  REP(i, N)
  cin >> S[i];
  // vector<vector<long long>> B(N, vector<long long>(N, INF));

  vector<vector<pair<long long, long long>>> dp(N, vector<pair<long long, long long>>(N, {INF, 0}));
  REP(i, N)
  {
    REP(j, N)
    {
      if (S[i][j] == 'Y')
        dp[i][j] = {1, -A[j]};
    }
  }

  // 入力: A[i][j] = 頂点iと頂点jを結ぶ辺の重み
  // 出力: A[i][j] = 頂点iから頂点jまでの最短路の重みの総和
  for (int k = 0; k < N; ++k)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        dp[i][j] = min(dp[i][j], {dp[i][k].first + dp[k][j].first, dp[i][k].second + dp[k][j].second});
      }
    }
  }

  int Q;
  cin >> Q;
  int u, v;
  REP(i, Q)
  {
    int cost, souvenir;
    cin >> u >> v;
    u--;
    v--;
    if (dp[u][v].first < INF)
    {
      cout << dp[u][v].first << ' ' << -dp[u][v].second + A[u] << '\n';
    }
    else
    {
      puts("Impossible");
    }
  }

  return 0;
}