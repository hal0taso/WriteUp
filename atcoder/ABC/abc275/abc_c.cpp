#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

bool is_square(vector<int> x, vector<int> y)
{
  vector<int> l(4);
  bool ret = true;
  REP(i, 4)
  {
    int j = (i + 1) % 4;
    l[i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  }
  REP(i, 4)
  {
    int j = (i + 1) % 4;

    if (l[i] != l[j])
      ret = false;
  }

  if ((x[0] - x[2]) * (x[1] - x[3]) + (y[0] - y[2]) * (y[1] - y[3]) != 0)
    ret = false;
  return ret;
}

int main()
{
  int N = 9;
  vector<string> s(N);
  REP(i, N)
  {
    cin >> s[i];
  }
  ll ans = 0;
  REP(x1, N)
  {
    REP(y1, N)
    {
      if (s[x1][y1] != '#')
        continue;
      // same row
      FOR(y2, y1 + 1, N)
      {
        int x2 = x1;
        if (s[x2][y2] != '#')
          continue;
        int l = y2 - y1;
        int x3 = x2 + l;
        if (x3 >= N)
          continue;
        int y3 = y2;
        int x4 = x3;
        int y4 = y1;
        if (s[x3][y3] == '#' && s[x4][y4] == '#')
          ans++;
      }
      // different row
      FOR(x2, x1 + 1, N)
      {
        FOR(y2, y1 + 1, N)
        {
          if (s[x2][y2] != '#')
            continue;
          int dx = x2 - x1;
          int dy = y2 - y1;
          int x3 = x2 + dy, y3 = y2 - dx;
          int x4 = x3 - dx, y4 = y3 - dy;
          if (x3 < N && y3 >= 0 && x4 >= 0 && y4 >= 0)
          {
            if (s[x3][y3] == '#' && s[x4][y4] == '#')
              ans++;
          }
        }
      }
    }
  }
  // ans /= 8;

  cout << ans << endl;

  return 0;
}
