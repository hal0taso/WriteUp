#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (long long i = 0; i < n; ++i)
#define FOR(i, a, b) for (long long i = a; i < b; ++i)

int main()
{
  long long x;
  cin >> x;
  vector<long long> bit;
  for (long long i = 0; (x >> i) > 0; i++)
  {
    if ((x >> i) & 1 == 1)
    {
      bit.push_back(i);
    }
  }
  REP(i, 1 << bit.size())
  {
    long long ans = 0;
    REP(j, bit.size())
    {
      if ((i >> j) & 1 == 1)
      {
        ans += (long long)1 << bit[j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
