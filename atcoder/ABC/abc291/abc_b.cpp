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
  vector<int> x;
  cin >> n;
  x.resize(5 * n);
  REP(i, 5 * n)
  cin >> x[i];
  sort(x.begin(), x.end());
  double ans = 0;
  FOR(i, n, 4 * n)
  {
    ans += (double)x[i];
  }
  ans /= (double)3 * n;
  cout << std::fixed << std::setprecision(7) << ans << '\n';
  return 0;
}
