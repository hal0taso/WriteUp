#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

constexpr long long INF = 1000000000LL;

const double TIME_LIMIT = 1900;

ll getTime()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  ll result = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
  // cerr << result << endl;
  return result;
}

void warshall_floyd(int n, vector<vector<ll>> &d)
{
  for (int k = 0; k < n; k++)
  { // 経由する頂点
    for (int i = 0; i < n; i++)
    { // 始点
      for (int j = 0; j < n; j++)
      { // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main()
{
  int n, m, d, k;
  cin >> n >> m >> d >> k;
  int u, v;
  ll w;
  vector<vector<ll>> D(n, vector<ll>(n, INF));
  vector<vector<ll>> origD(n, vector<ll>(n, INF));

  REP(i, m)
  {
    cin >> u >> v >> w;
    u--;
    v--;
    D[u][v] = w;
    origD[u][v] = w;
    // G[u].emplace_back(v, w);
    // G[v].emplace_back(u, w);
  }
  int x, y;
  REP(i, n)
  {
    cin >> x >> y;
  }
  vector<int> ans(m);
  int tmp = 1;
  int cnt = 0;
  REP(i, m)
  {
    ans[i] = (i % d) + 1;
  }
  mt19937_64 get_rand_mt;
  shuffle(ans.begin(), ans.end(), get_rand_mt);
  REP(i, m)
  {
    cout << ans[i];
    if (i < m - 1)
      cout << ' ';
    else
      cout << '\n';
  }

  return 0;
}
