#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  if (abs(b - c) > 1 || (a > 0 && d > 0 && a + d == n - 1))
    cout << "No";
  else
    cout << "Yes";
  cout << '\n';

  return 0;
}
