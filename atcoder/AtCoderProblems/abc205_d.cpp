#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ull i = a; i < b; ++i)
#define REP(i, n) for (ull i = 0; i < n; ++i)

int main() {
  ull n, q, ki;
  cin >> n >> q;
  vector<ull> a(n + 1);
  a[0] = 0;
  FOR(i, 1, n + 1) { cin >> a[i]; }
  // vector<ull> diff(n, 0);
  // FOR(i, 1, n + 1) { diff[i] = a[i] - a[i - 1] - 1; }
  vector<ull> accum(n, 0);
  accum[0] = 0; // diff[0];
  FOR(i, 1, n + 1) {
    accum[i] += accum[i - 1] + a[i] - a[i - 1] - 1;
  } // diff[i]; }
  REP(i, q) {
    cin >> ki;
    if (ki > accum[n]) {
      cout << a[n] + ki - accum[n] << endl;
    } else {
      ull ub = n;
      ull lb = 1;
      ull j = (ub + lb) / 2;
      while (ub - 1 > lb) {
        if (accum[j - 1] >= ki)
          ub = j;
        if (accum[j] <= ki)
          lb = j;
        j = (ub + lb) / 2;
      }
      cout << a[j] - 1 + ki - accum[j - 1] << endl;
    }
  }
  return 0;
}
