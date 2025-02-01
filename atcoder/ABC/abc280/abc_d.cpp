#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  long long k, p, a, n, ans, x;
  cin >> k;
  ans = 1;
  for (p = 2; p * p <= k; p++)
  {
    a = 0;
    while (k % p == 0)
      a++, k /= p;
    n = 0;
    while (a > 0)
    {
      n += p;
      x = n;
      while (x % p == 0)
        x /= p, a--;
    }
    ans = max(ans, n);
  }
  ans = max(ans, k);
  cout << ans << endl;

  return 0;
}
