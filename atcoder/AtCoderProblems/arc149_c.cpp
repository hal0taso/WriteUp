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
  vector<vector<int>> a(n, vector<int>(n, -1));
  vector<vector<int>> a3 = {{5, 3, 1}, {9, 7, 8}, {6, 2, 4}};
  set<int> odd;
  set<int> even;
  FOR(i, 1, n * n + 1)
  {
    if (i % 2 == 0)
      even.insert(i);
    else
      odd.insert(i);
  }

  if (n == 3)
  {
    REP(i, 3)
    {
      REP(j, 2)
      {
        cout << a3[i][j] << ' ';
      }
      cout << a3[i][2] << '\n';
    }
    return 0;
  }
  else if (n % 2 == 0)
  {
    int m = n * n - 1;
    REP(i, n)
    {
      a[n / 2 - 1][i] = 2 * (i + 1);
      a[n / 2][i] = m - a[n / 2 - 1][i];
      even.erase(2 * (i + 1));
      odd.erase(m - a[n / 2 - 1][i]);
    }
    REP(i, n / 2 - 1)
    {
      REP(j, n)
      {
        a[i][j] = *even.begin();
        even.erase(a[i][j]);
      }
    }
    FOR(i, n / 2 + 1, n)
    {
      REP(j, n)
      {
        a[i][j] = *odd.begin();
        odd.erase(a[i][j]);
      }
    }
  }
  else
  {
    a[n / 2][n / 2] = 7;
    a[n / 2 - 1][n / 2] = n * n - 7;
    odd.erase(7);
    even.erase(n * n - 7);
    a[n / 2][n / 2 - 1] = 8;
    a[n / 2 + 1][n / 2 - 1] = n * n - 8;
    even.erase(8);
    odd.erase(n * n - 8);
    REP(i, n / 2)
    {
      REP(j, n)
      {
        if (a[i][j] < 0)
        {
          a[i][j] = *even.begin();
          even.erase(a[i][j]);
        }
      }
    }
    REP(j, n / 2 - 1)
    {
      a[n / 2][j] = *even.begin();
      even.erase(a[n / 2][j]);
    }
    FOR(j, n / 2 + 1, n)
    {
      a[n / 2][j] = n * n - a[n / 2 - 1][j];
      odd.erase(a[n / 2][j]);
    }
    FOR(i, n / 2 + 1, n)
    {
      REP(j, n)
      {
        if (a[i][j] < 0)
        {
          if (a[i - 1][j] > 0 && a[i - 1][j] % 2 == 0)
          {
            a[i][j] = n * n - a[i - 1][j];
            odd.erase(a[i][j]);
          }
          else
          {
            a[i][j] = *odd.begin();
            odd.erase(a[i][j]);
          }
        }
      }
    }
  }
  // output
  REP(i, n)
  {
    REP(j, n - 1)
    {
      cout << a[i][j] << ' ';
    }
    cout << a[i][n - 1] << '\n';
  }
  return 0;
}
