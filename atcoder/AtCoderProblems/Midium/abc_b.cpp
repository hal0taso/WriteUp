#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

long long MOD = 998244353;

int main()
{
  vector<string> s(10);
  REP(i, 10)
  {
    cin >> s[i];
  }
  int a = 9, b = 0, c = 9, d = 0;
  REP(i, 10)
  {
    REP(j, 10)
    {
      if (s[i][j] == '#')
      {
        a = min(a, i);
        b = max(b, i);
        c = min(c, j);
        d = max(d, j);
      }
    }
  }
  cout << a + 1 << ' ' << b + 1 << '\n';
  cout << c + 1 << ' ' << d + 1 << '\n';

  return 0;
}
