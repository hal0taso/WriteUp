#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const ll C = 1e6;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h + 1, vector<int>(w + 1, -1));
  vector<vector<int>> dp(h + 1, vector<int>(h, C));
  FOR(i, 1, h + 1)
  {
    FOR(j, 1, w + 1)
    {
      cin >> a[i][j];
    }
  }
  FOR(i, 2, 3)
  {
    FOR(j, i - 1, i)
    {
      dp[i][j]
    }
  }
  return 0;
}
