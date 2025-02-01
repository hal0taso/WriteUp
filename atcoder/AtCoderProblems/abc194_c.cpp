#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  ull n, ans = 0;
  cin >> n;
  vector<ull> a(n, 0);
  vector<ull> t1(n, 0), t2(n, 0), t3(n, 0);
  ull tmp2 = 0;
  ull tmp3 = 0;
  REP(i, n)
  {
    cin >> a[i];
    if (i > 0)
    {
      t1[i] = i * a[i] * a[i];
    }
    tmp2 += a[i] * a[i];
    t2[i] = tmp2;
    tmp3 += a[i];
    t3[i] = tmp3;
  }
  REP(i, n) { ans += t1[i]; }
  REP(i, n - 1) { ans += t2[i] - 2 * a[i + 1] * t3[i]; }
  cout << ans << endl;
  return 0;
}
