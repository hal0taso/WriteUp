#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, m;
  cin >> n >> m;
  FOR(i, 1, 10)
  {
    if (m % i == 0 && (m / i) % 2)
    {
      if (m / i != 5)
      {
        return;
      }
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
