#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n, cnt = 0, k;
  cin >> n >> k;
  int ub = n;
  double ans = 0;
  while (k > 0 & ub > 0) {
    ans += (double)max(ub - k + 1, 0) / (double)(n * pow(2, cnt));
    ub = min(k - 1, ub);
    if (k % 2)
      k++;
    k /= 2;
    cnt++;
  }
  cout << fixed << setprecision(15) << ans << endl;

  return 0;
}
