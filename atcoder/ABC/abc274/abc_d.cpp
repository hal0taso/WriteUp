#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int N, x, y;
  int base = 1e4 + 10;
  cin >> N >> x >> y;
  vector<int> A(N);
  REP(i, N)
  {
    cin >> A[i];
  }
  vector<vector<int>> dpx(2, vector<int>(20021, 0));
  vector<vector<int>> dpy(2, vector<int>(20021, 0));
  dpx[0][base] = 1;
  dpx[1][A[0] + base] |= dpx[0][base];

  dpy[0][base] = 1;
  dpy[1][A[1] + base] |= dpy[0][base];
  dpy[1][-A[1] + base] |= dpy[0][base];
  int xi = 1, yi = 1;
  FOR(i, 2, N)
  {
    FOR(m, -10000, 10000 + 1)
    {
      if (i % 2 == 0)
        dpx[(xi + 1) % 2][m + base] = 0;
      else
        dpy[(yi + 1) % 2][m + base] = 0;
    }
    FOR(m, -10000, 10000 + 1)
    {
      if (i % 2 == 0)
      {
        dpx[(xi + 1) % 2][m + A[i] + base] |= dpx[xi % 2][m + base];
        dpx[(xi + 1) % 2][m - A[i] + base] |= dpx[xi % 2][m + base];
      }
      else
      {
        dpy[(yi + 1) % 2][m + A[i] + base] |= dpy[yi % 2][m + base];
        dpy[(yi + 1) % 2][m - A[i] + base] |= dpy[yi % 2][m + base];
      }
    }
    if (i % 2 == 1)
      yi++;
    else
      xi++;
  }
  if (dpx[(xi) % 2][x + base] > 0 && dpy[(yi) % 2][y + base] > 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
