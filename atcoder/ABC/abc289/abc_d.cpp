#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n)
  cin >> a[i];
  int m;
  cin >> m;
  // vector<int> b(m);
  // set<int> b;
  vector<int> b(100001, 0);
  int bi;
  REP(i, m)
  {
    cin >> bi;
    b[bi]++;
  }
  int x;
  cin >> x;

  vector<bool> dp(x + 1, false);
  dp[0] = true;
  REP(i, x + 1)
  {
    REP(j, n)
    {
      if (i + a[j] <= x)
      {
        if (b[i] == 0)
          dp[i + a[j]] = dp[i] || dp[i + a[j]];
      }
    }
  }
  if (dp[x])
  {
    puts("Yes");
  }
  else
    puts("No");
  return 0;
}
