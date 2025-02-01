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
  string s, t;
  cin >> n >> s >> t;
  int c = 0;
  REP(i, n)
  {
    if (s[i] != t[i])
      c++;
  }
  if (c % 2 == 1)
  {
    cout << -1 << endl;
    return 0;
  }
  c /= 2;
  int sn = c, tn = c;
  vector<int> ans(n);
  REP(i, n)
  {
    if (s[i] == t[i])
    {
      ans[i] = 0;
    }
    else
    {
      if (s[i] == '0')
      {
        if (sn > 0)
        {
          ans[i] = 0;
          sn--;
        }
        else
        {
          ans[i] = 1;
          tn--;
        }
      }
      if (t[i] == '0')
      {
        if (tn > 0)
        {
          ans[i] = 0;
          tn--;
        }
        else
        {
          ans[i] = 1;
          sn--;
        }
      }
    }
  }
  REP(i, n)
  {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
