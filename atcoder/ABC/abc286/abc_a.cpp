#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  // p--, q--, r--, s--;
  vector<int> A(n + 1);
  FOR(i, 1, n + 1)
  cin >> A[i];
  for (int i = 1; i < p; i++)
  {
    cout << A[i];
    if (i < n)
    {
      cout << ' ';
    }
    else
    {
      cout << '\n';
    }
  }
  for (int i = r; i <= s; i++)
  {
    cout << A[i];
    if (i < n)
    {
      cout << ' ';
    }
    else
    {
      cout << '\n';
    }
  }
  for (int i = q + 1; i < r; i++)
  {
    cout << A[i];
    if (i < n)
    {
      cout << ' ';
    }
    else
    {
      cout << '\n';
    }
  }
  for (int i = p; i <= q; i++)
  {
    cout << A[i];
    if (i < n)
    {
      cout << ' ';
    }
    else
    {
      cout << '\n';
    }
  }
  for (int i = s + 1; i <= n; i++)
  {
    cout << A[i];
    if (i < n)
    {
      cout << ' ';
    }
    else
    {
      cout << '\n';
    }
  }
  return 0;
}
