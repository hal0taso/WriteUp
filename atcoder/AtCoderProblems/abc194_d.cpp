#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (long i = a; i < b; ++i)
#define REP(i, n) for (long i = 0; i < n; ++i)

int main() {
  ld n;
  cin >> n;
  ld ans = 0.0;
  FOR(i, 1, n) { ans += (ld)n / (ld)i; }
  cout << fixed << setprecision(15) << ans;
  return 0;
}
