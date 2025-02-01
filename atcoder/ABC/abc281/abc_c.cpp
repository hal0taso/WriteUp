#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  ll n, t, total = 0;
  cin >> n >> t;
  vector<ll> a(n + 1, 0);
  FOR(i, 1, n + 1)
  {
    cin >> a[i];
    total += a[i];
    a[i] = total;
  }

  t %= total;
  if (t < 0)
  {
    t += total;
  }

  REP(i, n + 1)
  {
    if (a[i] < t)
    {
      continue;
    }
    else
    {
      cout << i << ' ' << t - a[i - 1] << endl;
      break;
    }
  }

  return 0;
}