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

  vector<int> a(n), c(n), x(m);
  REP(i, n)
  cin >> a[i];
  REP(i, n)
  cin >> c[i];
  REP(i, m)
  cin >> x[i];

  return 0;
}
