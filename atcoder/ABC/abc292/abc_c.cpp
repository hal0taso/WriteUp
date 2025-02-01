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
  vector<ll> a(n + 1, 0);
  FOR(k, 1, n + 1)
  {
    for (int i = 1; i * i <= k; i++)
    {
      if (k % i == 0)
      {
        if (i * i != k)
          a[k]++;
        a[k]++;
      }
    }
  }
  ll ans = 0;

  int l = 1, r = n - 1;
  while (l <= r)
  {
    ans += (a[l] * a[r]);
    if (l < r)
    {
      ans += (a[l] * a[r]);
    }
    l++;
    r--;
  }
  cout << ans << '\n';

  return 0;
}
