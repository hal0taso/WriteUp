#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  vector<vector<int>> a(m);
  REP(i, m)
  {
    cin >> c[i];
    a[i].resize(c[i]);
    REP(j, c[i])
    {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  REP(i, 1 << m)
  {
    vector<bool> b(n, false);
    REP(j, m)
    {
      if (i >> j & 1 == 1)
      {
        REP(k, c[j])
        {
          b[a[j][k] - 1] = true;
        }
      }
    }
    bool tmp = true;
    REP(j, n) { tmp &= b[j]; }
    if (tmp)
    {
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}
